#include <iostream>
#include <map>
#include <exception>
#include <sstream>
using namespace std;
template <typename Key,typename Value>
Value& GetRefStrict(map<Key,Value>& m,const Key& key){
        if (m.count(key) == 1) {
            return m.at(key);
        }else{
            stringstream ss;
            ss << "no values were found for this key " << endl;
            throw runtime_error(ss.str());
        }
}
int main() {
    map<int,string> m = {{1,"one"}, {2,"two"}, {3, "three"}, {4, "four"} };
    try {
        cout << GetRefStrict<int,string>(m, 4) << endl;
    }catch (exception& ex){
        cout << "exception happens: " << ex.what();
    }
    return 0;
}
