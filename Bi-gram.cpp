#include<bits/stdc++.h>
using namespace std;

int main () {
	ifstream myfile ("corpus.txt");
	string line;
	map<string,int> mp2;
	if (myfile.is_open()){
    while ( getline (myfile,line) ){

    	istringstream ss(line);
    	string word;
    	while( ss >> word){
    		mp2[word]++;
		}
    }
    }
    else cout << "Unable to open file";
    myfile.close();
	while(1){
	ifstream myfile ("corpus.txt");
    string line;
  
    int count = 0;
    string str,str1,str2,str3;
    map< string, pair < int,float > > mp;
	cout << "\nEnter the word to predict the next word:"  ;
    cin >> str1;

	if(myfile.is_open()){
		ostringstream ss;
		ss << myfile.rdbuf();
		str = ss.str();
	}
    else cout << "Unable to open file";

    myfile.close();
    istringstream ss(str);
    string word;
    
    while(ss>> word){
    	if(str1==word){
    		ss >> word;
    		mp[word].first++;
    		count++;
    		mp[word].second = ((float)mp[word].first+1.0)/((float)count+(float)mp2.size());
		}
	}
    vector < pair <float,string> > v;
	for(map<string, pair <int,float>  >::const_iterator it = mp.begin();
    it != mp.end(); ++it){
    //std::cout << it->first << " " << it->second <<  "\n";
    v.push_back(make_pair(it->second.second,it->first));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout<< v[i].second << " " << v[i].first << endl;
	}
	}
 
  return 0;
}
