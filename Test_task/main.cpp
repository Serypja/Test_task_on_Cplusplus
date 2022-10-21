#include<iostream>

class Queue {

private:
    uint16_t   Head;   // ��������� �� ������ �������
    uint16_t   Tail;   // ��������� �� ����� �������
    uint16_t   Size;   // ������ �������
    uint8_t* hData; // ������ �������

public:
    Queue(uint16_t iSize) { // ��� �������� �������, ��������� �� ������
        this->Head = NULL;
        this->Tail = NULL;
        this->Size = iSize; // ���������� ������ �������
        this->hData = new uint8_t[this->Size]; // �������� ����������� �������  
    };

    ~Queue(void) {
        delete[] this->hData; // �������� ����������� �������
    };

    void Head_and_Tail(void) {
        this->Head = this->hData[0];
        this->Tail = this->hData[this->Size - 1];
    }

    // ��������� ������ � �������, ���������� ���������� ����������� ������ ��� ����, 
    // ���� ������ �� ������� ��������� � �������. ���� ����� � ������� �� �������, �� �������� �� � �������.
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
            return this->Size; // ����������� ���������� ������
    };

    uint16_t GetSize(void) {  // �������� ������ ������ � �������
        int32_t size_queue = 0;
        for (uint16_t i = 0; i < this->Size; i++) {
            size_queue += sizeof(this->hData[i]);
        }
        return size_queue;
    };

    uint16_t Get(uint8_t* Data, uint16_t Size) { // ??? �������� ������ �� �������, ����� ��������� ������ ��� ����, ���������� ����� ���������� ����.
        uint16_t Size_new = Size; // ����� ������ ������ �������
        uint8_t* q1 = new uint8_t[Size_new]; // ������ ����� ������������ ������
        uint16_t schetch = 0;

        for (uint16_t i = 0; i < Size_new; i++) {
            Data[i] = this->hData[i];
            schetch += 1;
        }

        for (uint16_t i = schetch; i < Size_new; i++) {
            q1[i] = this->hData[i];
            schetch += 1;
        }

        delete[] this->hData; // ������ ������ ������
        this->Size = Size_new - schetch; // ������ ����� ������ �������
        this->hData = new uint8_t[this->Size]; // ������ ����� ������������ ������

        for (uint16_t i = 0; i < this->Size; i++) {
            this->hData[i] = q1[i];
            schetch += 1;
        }

        Head_and_Tail();

        delete[] q1;

        return sizeof(Size);
    };

    uint16_t Clear(uint16_t Size) { // �������� � ������� ��������� ���������� ����, � ������, ���������� ��������� ���������� ���� ��� ����.
        uint16_t Size_new = (this->Size - Size); // ����� ������ ������ �������
        uint8_t* q1 = new uint8_t[Size_new]; // ������ ����� ������������ ������

        for (uint16_t i = 0; i < Size_new; i++) { // ������ ������ � ����� ������ (��������� ������ ���������)
            q1[i] = this->hData[i];
        }

        delete[] this->hData; // ������ ������ ������
        this->Size = Size_new; // ������ ����� ������ �������
        this->hData = new uint8_t[this->Size]; // ������ ����� ������������ ������

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
            return Size; // ������� ���������� ���������� ����
        }
    };
};

int main() {
    const uint16_t size = 20;
    Queue a(size);
    uint8_t mass[size] = { 2, 10, 44, 5, 8, 25, 18, 33, 48, 99, 69, 10, 44, 5, 8, 2, 10, 44, 5, 1 };


    return 0;
}