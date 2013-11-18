#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h> 
#include <sstream>
#include <sys/stat.h>
#include <cstring>
#include <cstdio>
using namespace std;
int main(int argc,char** argv)
{
	stringstream cmd;
	cmd<<"./IndriRunQuery queryparam -index=/home/dan/Projects/id_"
					<<argv[1]<<" -trecFormat=true -baseline=tfidf,k1:1.0,b:0.3";
	FILE *fp =popen(cmd.str().c_str(),"r");
	char buf[1024];
ofstream result;
	result.open("results");
while (fgets(buf, 1024, fp)) {
  result<<buf;
}

fclose(fp);
}

