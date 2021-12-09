#include <iostream>
#include <getopt.h>
#include <vector>
#include <algorithm>


int main (int argc, char *argv[]){
	const char* short_options = "hvls:";

	const struct option long_options[] = {
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'v'},
		{"list", no_argument, NULL, 'l'},
		{"size", required_argument, NULL, 's'},
		{NULL,0,NULL,0}
	};

	int result;
	int option_index;

	std::vector<int> parsed_args;

	while ((result=getopt_long(argc,argv,short_options,long_options,&option_index))!=-1){

		if (std::find(parsed_args.begin(), parsed_args.end(), result) != parsed_args.end()){
			continue;
		}
		else {
			parsed_args.push_back(result);
		}

		switch (result)
		{
			case 'h':
				std::cout << "Arg: Help\n";
				break;
			case 'v':
				std::cout << "Arg: Version\n";
				break;
			case 'l':
				std::cout << "Arg: List\n";
				break;
			case 's':
				std::cout << "Arg: Size, value: " << optarg << std::endl;
				break;

			case '?':
				std::cout << "Unexpected argument\n";
				break;
			default:
				break;
		}
	}
	return 0;
}