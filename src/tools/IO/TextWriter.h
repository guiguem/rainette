#ifndef MYTOOL_H
#define MYTOOL_H

#include <string>
#include <iostream>

#include "Tool.h"
#include "MyTool.h"
// #include "RainetteDataModel.h"
class RainetteDataModel;


// class TestObject : public SerialisableObject
// {

//     friend class boost::serialization::access;

// public:
//     double aValue;
//     double bValue;

//     bool Print()
//     {
//         std::cout << "aValue : " << aValue << std::endl;
//         std::cout << "bValue : " << bValue << std::endl;
//         return true;
//     }

//     template <class Archive>
//     void serialize(Archive &ar, const unsigned int version)
//     {
//         if (serialise)
//         {
//             ar &aValue;
//             ar &bValue;
//         }
//     }
// };

class Hit : public SerialisableObject{
	
	friend class boost::serialization::access;
	
	public:
	Hit() : TubeId(0), Time(0), Charge(0){serialise=true;}
	Hit(int thetubeid, double thetime, double thecharge) : TubeId(thetubeid), Time(thetime), Charge(thecharge){serialise=true;}
	
	inline int GetTubeId() const {return TubeId;}
	inline double GetTime() const {return Time;}
	inline double GetCharge() const {return Charge;}
	
	inline void SetTubeId(int tubeid){TubeId=tubeid;}
	inline void SetTime(double tc){Time=tc;}
	inline void SetCharge(double chg){Charge=chg;}
	
	bool Print() {
		std::cout<<"TubeId : "<<TubeId<<std::endl;
		std::cout<<"Time : "<<Time<<std::endl;
		std::cout<<"Charge : "<<Charge<<std::endl;
		return true;
	}
	
	protected:
	int TubeId;
	double Time;
	double Charge;
	
	template<class Archive> void serialize(Archive & ar, const unsigned int version){
		if(serialise){
			ar & TubeId;
			ar & Time;
			ar & Charge;
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
