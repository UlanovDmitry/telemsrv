#include "config_loader.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;

class Date {
public:
  Date(uint16_t year, uint8_t month, uint8_t day)
      : _year(year), _month(month), _day(day) {}

  /* getYear/setYear, getMonth/setMonth etc skipped */
  Document toJSON() {
    Document doc;
    auto &allocator = doc.GetAllocator();
    doc.SetArray()
        .PushBack(_year, allocator)
        .PushBack(_month, allocator)
        .PushBack(_day, allocator);
    return doc;
  }

  static Date fromJSON(const Value &doc) {
    if (!doc.IsArray())
      throw std::runtime_error("document is not an array");

    if (doc.Size() != 3)
      throw std::runtime_error("wrong array size");

    uint16_t year = doc[0].GetInt();
    uint8_t month = doc[1].GetInt();
    uint8_t day = doc[2].GetInt();

    Date result(year, month, day);
    return result;
  }

private:
  uint16_t _year;
  uint8_t _month;
  uint8_t _day;
};

void ConfigLoader::doSmth() {
  Date dt(2020, 2, 2);
  Document doc = dt.toJSON();
  StringBuffer buffer;
  PrettyWriter<StringBuffer> writer(buffer);
  doc.Accept(writer);

  std::cout << buffer.GetString() << std::endl;
}
