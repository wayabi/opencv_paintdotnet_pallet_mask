#ifndef __U_ARG_PARSE__
#define __U_ARG_PARSE__

#include <string>
#include <ostream>

#include <boost/program_options.hpp>

class arg_parse {

public:
	std::string path_color;
	std::string path_mask;
	std::string path_output;
public:
	std::string parse(int argc, const char** argv)
	{
		using namespace boost::program_options;
		options_description opt("opt");
		opt.add_options()
			("path_color", value<std::string>()->default_value(""), "path_color")
			("path_mask", value<std::string>()->required(), "path_mask")
			("path_output", value<std::string>()->default_value(""), "path_output")
		;
		variables_map vm;
		try{
			store(parse_command_line(argc, argv, opt), vm);
			notify(vm);
			path_color = vm["path_color"].as<std::string>();
			path_mask = vm["path_mask"].as<std::string>();
			path_output = vm["path_output"].as<std::string>();
		}catch(std::exception& e){
			return std::string(e.what());
		}
		return std::string();
	}

	void print(std::ostream& o)
	{
		o << "path_color[std::string]: " << path_color << std::endl;
		o << "path_mask[std::string]: " << path_mask << std::endl;
		o << "path_output[std::string]: " << path_output << std::endl;
	}
};
#endif
