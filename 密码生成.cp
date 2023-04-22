#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main()
{
    // 使用当前时间作为随机种子
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine engine(seed);  // 创建随机数引擎

    int password_length;  // 密码长度
    bool include_lowercase;  // 是否包含小写字母
    bool include_uppercase;  // 是否包含大写字母
    bool include_digits;  // 是否包含数字
    bool include_symbols;  // 是否包含其他符号

    // 输入用户所需的密码配置
    cout << "请输入密码长度：";
    cin >> password_length;

    char choice;
    cout << "是否包含小写字母(Y/N)？";
    cin >> choice;
    include_lowercase = (choice == 'Y' || choice == 'y');

    cout << "是否包含大写字母(Y/N)？";
    cin >> choice;
    include_uppercase = (choice == 'Y' || choice == 'y');

    cout << "是否包含数字(Y/N)？";
    cin >> choice;
    include_digits = (choice == 'Y' || choice == 'y');

    cout << "是否包含其他符号(输入 Y 或 N)？";
    cin >> choice;
    include_symbols = (choice == 'Y' || choice == 'y');

    // 根据用户指定的要求生成密码
    string password = "";

    if (include_lowercase)
        password += "abcdefghijklmnopqrstuvwxyz";
    if (include_uppercase)
        password += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (include_digits)
        password += "0123456789";
    if (include_symbols)
        password += "~!@#$%^&*()_+`-=\\|][{}\"';:/?.>,<";

    uniform_int_distribution<int> distribution(0, password.length() - 1);

    cout << "你的随机密码是：";
    for (int i = 0; i < password_length; ++i)
        cout << password[distribution(engine)];
    cout << endl;

    return 0;
}