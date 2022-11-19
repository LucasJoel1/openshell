#include "../libraries.h"

void parse(string toBeParsed) {
    vector<string> parsedVector;
    regex e("-([\\w]+)+ ([\\w]+)+");
    sregex_token_iterator iter(toBeParsed.begin(), toBeParsed.end(), e, 0);
    sregex_token_iterator end;
    for(; iter != end; ++iter) {
        parsedVector.push_back(*iter);
    }
    for(int i = 0; i < parsedVector.size(); i++) {
        cout << parsedVector[i] << endl;
    }
}