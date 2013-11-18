#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <string.h>
#include <iterator>
#include <algorithm>
#include "rapidxml/rapidxml.hpp"
using namespace rapidxml;
using namespace std;
int main(int argc, char **argv)
{
	char* fn;
    fn = argv[1];
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile (fn);
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("parameters");
	// Get RequestType
	//string requestType = root_node->first_node("requestType")->value();
	xml_node<> * resourceList = root_node->first_node("resourceList");
	//Create vectors
	vector<string> id;
	vector<string>content;
	for (xml_node<> * resource_node = resourceList->first_node("resource"); resource_node; resource_node = resource_node->next_sibling())
	{
	id.push_back(resource_node->first_node("id")->value());
	string str = resource_node->first_node("content")->value();
	str.erase(std::remove(str.begin(), str.end(), '.'), str.end());
	content.push_back(str);
	
	}
	vector< vector<string> > xml(2);
	xml[0]=id;
	xml[1]=content;
	//write to trec
	ofstream newfile;
	newfile.open("input/inputfile");
	for(unsigned int i=0;i<id.size();i++)
	{
	newfile<<"<DOC>\n";
	newfile<<"<DOCNO>";
	newfile<<xml[0][i];
	newfile<<"</DOCNO>\n";
	newfile<<"<TEXT>\n";
	newfile<<xml[1][i];
	newfile<<"\n</TEXT>\n";
	newfile<<"</DOC>\n";
	}
	return 0;
}

