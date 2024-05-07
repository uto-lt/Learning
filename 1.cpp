#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

std::string decimalToHex(uint64_t decimal) {
    std::stringstream ss;
    ss << std::hex << decimal; // 将整数转换为十六进制表示形式
    return ss.str(); // 返回十六进制字符串
}


void vector_2dim_space()
{
    int row = 5;
    vector<vector<int>> v(row, { 1,2,3 });
    for (int i = 0; i < row; i++)
    {
        string temp;
        stringstream ss;
        ss << "v[" << i << "]";
        ss >> temp;

        cout << temp << "地址：" << &v[i] << " " << *((uint64_t*)(&v[i])) << " " << decimalToHex(*(((uint64_t*)(&v[i]))+2));
        for (int j = 0; j < 3; j++)
        {
            ss.clear();
            ss << "v[" << i << "]" << "[" << j << "]";
            ss >> temp;
            cout << temp << "地址：" << &v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << sizeof(vector<short>) << endl;
    vector_2dim_space();
    return 0;
}
