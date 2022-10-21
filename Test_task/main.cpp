#include<iostream>

class Queue {

private:
    uint16_t   Head;   // ”казатель на голову очереди
    uint16_t   Tail;   // ”казатель на хвост очереди
    uint16_t   Size;   // –азмер очереди
    uint8_t* hData; // ƒанные очереди

public:
    Queue(uint16_t iSize) { // ѕри создании очереди, указываем ее размер
        this->Head = NULL;
        this->Tail = NULL;
        this->Size = iSize; // «аписываем размер очереди
        this->hData = new uint8_t[this->Size]; // создание днамичекого массива  
    };

    ~Queue(void) {
        delete[] this->hData; // ”даление днамичекого массива
    };

    void Head_and_Tail(void) {
        this->Head = this->hData[0];
        this->Tail = this->hData[this->Size - 1];
    }

    // ѕоместить данные в очередь, возвращаем количество добавленныз данных или ноль, 
    // если данные не удалось поместить в очередь. ≈сли место в очереди не хватает, не помещаем их в очередь.
    uint16_t Put(uint8_t* Data, uint16_t Size) {
        if (Size > 0) {
            for (uint16_t i = 0; i < this->Size; i++) {
                this->hData[i] = Data[i];
            }
            Head_and_Tail();
        }

        if (Size <= 0)
            return 0;
        else
            return this->Size; // колчисечтво добавенных данных
    };

    uint16_t GetSize(void) {  // ѕолучить размер данных в очереди
        int32_t size_queue = 0;
        for (uint16_t i = 0; i < this->Size; i++) {
            size_queue += sizeof(this->hData[i]);
        }
        return size_queue;
    };

    uint16_t Get(uint8_t* Data, uint16_t Size) { // ??? ѕолучить данные из очереди, можно запросить больше чем есть, возвращаем число полученных байт.
        uint16_t Size_new = Size; // узнаЄм размер нового массива
        uint8_t* q1 = new uint8_t[Size_new]; // —оздаЄм новый динамический массив
        uint16_t schetch = 0;

        for (uint16_t i = 0; i < Size_new; i++) {
            Data[i] = this->hData[i];
            schetch += 1;
        }

        for (uint16_t i = schetch; i < Size_new; i++) {
            q1[i] = this->hData[i];
            schetch += 1;
        }

        delete[] this->hData; // ”дал€ю старый массив
        this->Size = Size_new - schetch; // —оздаю новый размер массива
        this->hData = new uint8_t[this->Size]; // —оздаю новый динамический массив

        for (uint16_t i = 0; i < this->Size; i++) {
            this->hData[i] = q1[i];
            schetch += 1;
        }

        Head_and_Tail();

        delete[] q1;

        return sizeof(Size);
    };

    uint16_t Clear(uint16_t Size) { // ќчистить в очереди указанное количество байт, с хвоста, возвращаем очищенное количество байт или ноль.
        uint16_t Size_new = (this->Size - Size); // узнаЄм размер нового массива
        uint8_t* q1 = new uint8_t[Size_new]; // —оздаЄм новый динамический массив

        for (uint16_t i = 0; i < Size_new; i++) { // «апись данных в новый массив (удавление первых элементов)
            q1[i] = this->hData[i];
        }

        delete[] this->hData; // ”дал€ю старый массив
        this->Size = Size_new; // —оздаю новый размер массива
        this->hData = new uint8_t[this->Size]; // —оздаю новый динамический массив

        for (uint16_t i = 0; i < this->Size; i++) {
            this->hData[i] = q1[i];
            Size += 1;
        }

        Head_and_Tail();

        delete[] q1;



        if (Size <= 0) {
            return 0;
        }
        else {
            return Size; // ¬озврат очищенного количества байт
        }
    };
};

int main() {
    const uint16_t size = 20;
    Queue a(size);
    uint8_t mass[size] = { 2, 10, 44, 5, 8, 25, 18, 33, 48, 99, 69, 10, 44, 5, 8, 2, 10, 44, 5, 1 };


    return 0;
}