#include "json.h"


JsonValue::StringValue::StringValue(const std::string& str):
    m_value { str } {}

void JsonValue::StringValue::print() const { 
    std::cout << "\"" << m_value << "\""; 
}

std::string JsonValue::StringValue::toString() const {
    return m_value;
}

JsonValue::ObjectValue::ObjectValue(const JsonObject& obj):
    m_value { std::make_shared<JsonObject>(obj) } {}

void JsonValue::ObjectValue::print() const {
    m_value->print();
}

std::string JsonValue::ObjectValue::toString() const {
    return m_value->toString();
}

JsonValue::JsonValue() : m_value { nullptr } {}

JsonValue::JsonValue(const std::string& str):
    m_value { std::make_shared<StringValue>(str) } {}

JsonValue::JsonValue(const JsonObject& obj):
    m_value { std::make_shared<ObjectValue>(obj) } {}

bool JsonValue::isString() const {
    return dynamic_cast<StringValue*>(m_value.get()) != nullptr;
}

bool JsonValue::isObject() const {
    return dynamic_cast<ObjectValue*>(m_value.get()) != nullptr;
}

std::string JsonValue::asString() const {
    auto ptr = dynamic_cast<StringValue*>(m_value.get());
    if(!ptr) throw std::runtime_error("JsonValue is not a string");
    return ptr->m_value;
}

JsonObject JsonValue::asObject() const {
    auto ptr = dynamic_cast<ObjectValue*>(m_value.get());
    if(!ptr) throw std::runtime_error("JsonValue is not a JsonObject");
    return *(ptr->m_value);
}

void JsonValue::print() const {
    if(m_value) m_value->print();
    else std::cout << "null";
}

std::string JsonValue::toString() const{
    if(m_value) return m_value->toString();
    else return "null";
}

void JsonObject::add(const std::string& key, const JsonValue& value) {
    m_data[key] = value;
}

JsonValue JsonObject::get(const std::string& key) const {
    auto it { m_data.find(key) };
    if(it != m_data.end()) {
        return it->second;
    }
    throw std::runtime_error("Key not found");
}

void JsonObject::print() const {
    std::cout << "{";
    for(auto it = m_data.begin(); it != m_data.end(); ++it) {
        std::cout <<  "\"" << it->first << "\": ";
        it->second.print();
        if(std::next(it) != m_data.end()) std::cout << ", ";
    }
    std::cout << "}";
}

std::string JsonObject::toString() const {
    std::string ret { "{" };
    for(auto it = m_data.begin(); it != m_data.end(); ++it) {
        ret += "\"" + it->first + "\": ";
        ret += it->second.toString();
        if(std::next(it) != m_data.end())  ret += ", ";
    }
    ret += "}";
    return ret;
}