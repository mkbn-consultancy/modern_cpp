//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <string>
#include <tuple>

class DbHhandler{/*...*/};
DbHhandler db;
void process(const std::string& str){}

//----------- solution 1 -----------//
void readFromDB( DbHhandler* h, std::string& rs, bool& valid) {}

void solution_1(){
    DbHhandler db;
    std::string result;
    bool bValid;
	readFromDB(&db, result, bValid);
	if(bValid){
	  process(result);
	}
}

//----------- solution 2 -----------//

bool readFromDB(DbHhandler* h, std::string& rs){return true;}

void solution_2(){
    DbHhandler db;
    std::string result;

    if(readFromDB(&db,result)){
        process(result);
    }
}

//----------- solution 3 -----------//

std::pair<std::string, bool> readFromDB( DbHhandler* h){ return std::pair<std::string,bool>("test",true);}

void solution_3(){
    DbHhandler db;
	std::pair<std::string, bool> rs = readFromDB(&db);
	if(rs.second){
	  process( rs.first);
	}
}

//----------- solution 4 -----------//

const std::string& readFromDB_2( DbHhandler* h){ static std::string s = "testing"; return s; }
bool result_ok(const DbHhandler* h) {return true;}

void solution_4(){
    DbHhandler db;
	const std::string& rs = readFromDB_2(&db);
	if(result_ok(&db)){
	  process(rs);
	}
}

std::pair<std::string, bool> readFromDB( DbHhandler* h);

int main_4()
{
    DbHhandler db;
	auto rs = readFromDB(&db);
	if( rs.second){
	  process(rs.first);
	}
	return 0;
}

//----------- solution 5 -----------//

//std::tuple<std::string,bool> 
auto readFromDB_5( DbHhandler* h)
{
  std::string s;
  bool b;

  /*read data from db into s, using the handler, saving the status in b*/
 
  return make_tuple(s,b);
}


int main_5(){
  std::string s; bool valid;

  tie(s,valid) = readFromDB(&db);

  if( valid){
    process( s);
  }
  return 0;
}
