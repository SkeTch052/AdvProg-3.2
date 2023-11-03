#include <iostream>

class smart_array {
private:
    int* array;
    int count, size;
public:
    smart_array(int user_size) {
        size = user_size;
        count = 0;
        array = new int[size] {};
    }
    void add_element(int elem) {
        if (count >= size) {
            throw std::exception("ERROR 1: The number of elements is greater than the number of elements for which memory is allocated");
        }
        else {
            array[count] = elem;
            count++;
        }
    }
    int get_element(int index) {
        if (index <= 0 || index > size) {
            throw std::exception("ERROR 2: Wrong index");
        }
        else {
            return array[index - 1];
        }
    }
    smart_array& operator=(const smart_array& created_smart_array)
    {
        if (&created_smart_array != this) {
            for (int i = 0; i < size; i++) {
                array[i] = created_smart_array.array[i];
            }
            size = created_smart_array.size;
        }
        return *this;
    }
    ~smart_array() {
        delete[] array;
        count = 0;
    }
};

int main()
{
    try {
      smart_array arr(5);
      arr.add_element(1);
      arr.add_element(4);
      arr.add_element(155);

      smart_array new_array(2);
      new_array.add_element(44);
      new_array.add_element(34);

      arr = new_array;
      std::cout << arr.get_element(1) << std::endl;
      std::cout << arr.get_element(2) << std::endl;
      std::cout << arr.get_element(3) << std::endl;
    }
    catch (const std::exception& ex) {
      std::cout << ex.what() << std::endl;
    }
    return 0;
}