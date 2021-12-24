#include <iostream>
#include <array>

struct Stash{

    int size;
    int count;
    int array_count;
    int* int_s;
    char* char_s;
    char* type_s;
    int* array_start;
    int* array_end;

    Stash(){

        size = 1;
        
        type_s = new char[size];
        char_s = new char[size];
        int_s = new int[size];

        array_count = 0;
        count = 0;

        array_start = new int[0];
        array_end = new int[0];
    }

    Stash (const Stash& other){

        size = other.size;

        array_count = other.array_count;
        count = other.count;

        type_s = new char[size];
        char_s = new char[size];
        int_s = new int[size];

        array_start = new int[array_count];
        array_end = new int[array_count];

        for (int i = 0; i < size; i++){

            type_s[i] = other.type_s[i];
            char_s[i] = other.char_s[i];
            int_s[i] = other.int_s[i];
        }

        for (int i = 0; i < array_count; i++){

            array_end[i] = other.array_end[i];
            array_start[i] = other.array_start[i];
        };

    }

    void increase_size(){

        int prev_size = size;
        size *= 2;


        char* temp_t = new char[size];

        for (int i = 0; i < prev_size; i++){

            temp_t[i] = type_s[i];
        }

        char* temp_c = new char[size];

        for (int i = 0; i < prev_size; i++){

            temp_c[i] = char_s[i];
        }



        int* temp_i = new int[size];

        for (int i = 0; i < prev_size; i++){

            temp_i[i] = int_s[i];
        }


        char* prev_type_s = type_s;
        type_s = temp_t;
        delete[] prev_type_s;

        char* prev_char_s = char_s;
        char_s = temp_c;
        delete[] prev_char_s;

        int* prev_int_s = int_s;
        int_s = temp_i;
        delete[] prev_int_s;

    }

    void append(int values){

        if (count == size){

            increase_size();
        }

        type_s[count] = 'i';
        int_s[count] = values;
        count++;

    }

    void append(char values){

        if (count = size){

            increase_size();
        }

        type_s[count] = 'c';
        char_s[count] = values;
        count++;
        
    }

    void append(Stash values){

        array_start[array_count] = count;

        for (int i = 1; i < values.array_count + 1; i++){

            array_end[array_count + i] = values.array_end[i] + count;
            array_start[array_count + i] = values.array_start[i] + count;
        }

        array_count += values.array_count;

        array_end[array_count] = count + values.count;

        array_count += 1;


        int temp_count = count;

        while (count < temp_count + values.count){

            if (count == size){

                increase_size();
            }

            if (values.type_s[count - temp_count] == 'c'){

                type_s[count] = 'c';
                char_s[count] = values.char_s[count - temp_count];
            }

            if (values.type_s[count - temp_count] == 'i'){

                type_s[count] = 'i';
                int_s[count] = values.int_s[count - temp_count];
            }

            count++;
        }
    }

    ~Stash(){

        delete[] type_s;
        delete[] char_s;
        delete[] int_s;

        delete[] array_end;
        delete[] array_start;
    }

};

std::ostream& operator <<(std::ostream& os, const Stash& stash){

    os << "[";

    for (int i = 0; i < stash.count; i++){

        for (int j = 0; j < stash.array_count; j++){

            if (i == stash.array_start[j]){

                os << "[";
            }
        }

        if (stash.type_s[i] == 'c'){

            os << stash.char_s[i];
        }

        if (stash.type_s[i] == 'i'){

            os << stash.int_s[i];
        }

        bool comma = true;

        for (int j = 0; j < stash.array_count; j++){

            if (i + 1 == stash.array_end[j]){

                os << "]";
                comma = false;
            }
        
        }

        if (i != stash.count - 1 && comma){

           os << ",";
        }    
    }

    os << "]" << std::endl;
    return os;
}
