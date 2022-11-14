#include "../libraries.h"

void parse(string toBeParsed) {
    vector<string> parsedVector;
    regex e("(-[a-z]+ ?[^ ]+)+");
    sregex_token_iterator iter(toBeParsed.begin(), toBeParsed.end(), e, -1);
    sregex_token_iterator end;
    for(; iter != end; ++iter) {
        parsedVector.push_back(*iter);
        cout << *iter << endl;
    }
}