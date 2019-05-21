#ifndef MYTOOL_H
#define MYTOOL_H

#include <string>
#include <iostream>

#include "Tool.h"
#include "MyTool.h"
// #include "RainetteDataModel.h"
class RainetteDataModel;

class TestObj : public SerialisableObject{
	
	friend class boost::serialization::access;
	
	public:
	TestObj() :  aValue(0), bValue(0){serialise=true;}
	TestObj(double theaValue, double thebValue) : aValue(theaValue), bValue(thebValue){serialise=true;}
	
	inline double GetA() const {return aValue;}
	inline double GetB() const {return bValue;}
	
	inline void SetA(double tc){aValue=tc;}
	inline void SetB(double chg){bValue=chg;}
	
	bool Print() {
		std::cout<<"aValue : "<<aValue<<std::endl;
		std::cout<<"bValue : "<<bValue<<std::endl;
		return true;
	}
	
	protected:
	double aValue;
	double bValue;
	
	template<class Archive> void serialize(Archive & ar, const unsigned int version){
		if(serialise){
			ar & aValue;
			ar & bValue;
		}
	}
};


class TextWriter : public Tool::Registrar<TextWriter>
{
public:
    TextWriter(std::string x) : m_x(x) {}

public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

private:
    int m_verbose;
    std::string m_x;
    std::string m_filename;
    std::ofstream m_file;

};

#endif
