#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>

class JsonObject;

class JsonValue{
private:
    class BaseValue {
        public:
            virtual ~BaseValue() = default;
            virtual void print() const = 0;
            virtual std::string toString() const = 0;
    };
    class StringValue : public BaseValue {
        public:
            std::string m_value;
            explicit StringValue(const std::string&);
            void print() const override;
            std::string toString() const override;
    };
    class ObjectValue : public BaseValue {
        public:
            std::shared_ptr<JsonObject> m_value;
            explicit ObjectValue(const JsonObject&);
            void print() const override;
            std::string toString() const override;
    };

    std::shared_ptr<BaseValue> m_value;
public:
    JsonValue();

    JsonValue(const std::string& str);
    JsonValue(const JsonObject& obj);

    bool isString() const;
    bool isObject() const;

    std::string asString() const;
    JsonObject asObject() const;

    void print() const;
    std::string toString() const;

};

class JsonObject {
private:
    std::unordered_map<std::string, JsonValue> m_data;

public:
    void add(const std::string&, const JsonValue&);
    JsonValue get(const std::string&) const;
    void print() const;
    std::string toString() const;
};


#endif