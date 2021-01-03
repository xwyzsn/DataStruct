#include<iostream>

#include<fstream>
#include <string>
using namespace std;


class file{
	
	public:
	
	void Insert(string name,string pwd);
	
	void remove(string name);
	
	string search(string name);


	
	private:
		fstream f;
};

void file::Insert(string name,string pwd){
	
	if(search(name)!="-1"){
		return;
	}

	
	f.open("1.txt",ios::app|ios::out);
	
	f<<name<<" "<<pwd<<endl;
	
	f.close(); 
	
}
void file::remove(string name){
	
		fstream tmpf;
		
		tmpf.open("2.txt",ios::out|ios::trunc);
		
		f.open("1.txt",ios::in);
		
		while(1){
			
			string str1,str2;
			f>>str1>>str2;
			if(str1!=name){
			
			tmpf<<str1<<" "<<str2<<endl;
		    }
			if(f.eof()){
				break; 
			}
			
		}  
	    
        f.close();
	    tmpf.close();
	    
	    tmpf.open("2.txt",ios::in);
		
		f.open("1.txt",ios::out|ios::trunc) ;
		
		while(1){
			
			string str1,str2;
			
			tmpf>>str1>>str2;
			
			f<<str1<<" "<<str2<<endl;
			if(tmpf.eof()){
				break;
			}
			
			
		} 
	    tmpf.close() ;
	    tmpf.open("2.txt",ios::trunc|ios::out);
	    
	    tmpf.close();
	    
	    f.close();
	    
}


string file::search(string name){
	
	f.open("1.txt",ios::in);
	
	while(1){
		
		string str,str2;
		
		f>>str>>str2;
		
		if(name==str){
			f.close();
			return str2;
		}
		else if(f.eof()){
			
			f.close();
			break;
			
		}
	} 
	f.close();
	return "-1";
	
}
