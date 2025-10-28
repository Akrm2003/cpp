#include "Serializer.hpp"

int main()
{
    Data data;
    data.number = 42;
    data.text = "Hello, World!";
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "uintptr_t: " << raw << std::endl;
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data content: number = " << data.number << ", text = " << data.text << std::endl;
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;
    std::cout << "Deserialized Data content: number = " << deserializedData->number << ", text = " << deserializedData->text << std::endl;
    return 0;
}