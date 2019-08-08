#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "test_json.h"
#include "utils.h"

using namespace rapidjson;

std::string readJsonStringFromFile(const std::string& filename) {
    std::ifstream inFile;
    inFile.open(filename);

    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();

    return str;
}

void test_json() {
    /*
    // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);

    // 2. Modify it by DOM.
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    */

    utils::Timer t;

    for (int i = 0; i < 100; i++) {
        std::string s = readJsonStringFromFile("./resources/rec-proxy-result.json");
        // std::cout << s << std::endl;

        Document d;
        t.reset();
        d.Parse(s.c_str());
        std::cout << t.elapsed_micro() << std::endl;

        Value& v = d["requestid"];
        std::cout << v.GetString() << std::endl;
    }
}
