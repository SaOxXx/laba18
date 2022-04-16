#pragma once
#include <map>
#include <list>
#include <string>
#include <cstdlib>
using namespace std;


class Multimap {
private:
	map<const string, list<int>> m;
public:
	Multimap() {}
	void insert(const string& key, int value){
		if (m.empty() == 1) { 
			list<int> l;
			l.push_back(value);
			
			m[key] = l;
		}
		else {
			map<const string, list<int>>::iterator p;
 			p = m.find(key);
			if (p != m.end()) {
				p->second.push_back(value);
			}
			else {
				list<int>l;
				l.push_back(value);
				m.insert(std::pair<const string&,list<int>&>(key, l));
			}
		}  
	}
	const list<int>& find(string& key) {
		map<const string, list<int>>::iterator p;
		p = m.find(key);
		if (p != m.end()) {
			return p->second;
		}
		else {
			list<int> l;
			m.insert(std::pair<const string&, list<int>&>(key, l));
			return l;
		}
	}
	void erase(const string& key) {
		map<const string, list<int>>::iterator p;
		p = m.find(key);
		if (p != m.end()) {
			m.erase(p);
		}
	}

	map<const string, list<int>>& return_map() {
		return m;
	}
	
	Multimap operator +(Multimap& dop) {
		  Multimap result;
		map<const string, list<int>>& dop_m = dop.return_map();
		

		for (map<const string, list<int>>::iterator p = m.begin(); p != m.end(); p++) {
			for (list<int>::iterator it = p->second.begin(); it != p->second.end(); it++) {
				result.insert(p->first, *it);
			}
		}

		for (map<const string, list<int>>::iterator p = dop.m.begin(); p != dop.m.end(); p++) {
			for (list<int>::iterator it = p->second.begin(); it != p->second.end(); it++) {
				result.insert(p->first, *it);
			}
		}
		return result;
	}



	Multimap operator +=(Multimap& other) {
		Multimap result;
		map<const string, list<int>>& dop_m = other.return_map();
		map<const string, list<int>>& result_m = result.return_map();

		for (map<const string, list<int>>::iterator p = m.begin(); p != m.end(); p++) {
			for (list<int>::iterator it = p->second.begin(); it != p->second.end(); it++) {
				result.insert(p->first, *it);
			}
		}

		for (map<const string, list<int>>::iterator p = other.m.begin(); p != other.m.end(); p++) {
			for (list<int>::iterator it = p->second.begin(); it != p->second.end(); it++) {
				result.insert(p->first, *it);
			}
		}
		*this = result;
		return *this; 
	}






	Multimap& operator=(Multimap A) {

		map<const string, list<int>>& dop_m = A.return_map();
		m = dop_m;
		return *this;
	}

};
ostream& operator<<(ostream& out, Multimap& a) {
	map<const string, list<int>>& m = a.return_map();
	map<const string, list<int>>::iterator p;

	p = m.begin();
	while (p != m.end()) {
		out << p->first << ":";
		for (list<int>::iterator i = p->second.begin(); i != p->second.end(); i++) {
			out << *i;
			out << "    ";
		}
		out << "\n";
		p++;
	}
	return out;

	



}
