#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define MAX_INPUT 255

// operations.txt 파일 생성
void makeTxtFile();
// 괄호가 balanced 된 입력인지 확인
bool checkBalanced(string on);
//‘&’ has higher precedence than ‘@’ and ‘#’
// postfix 로 바꿔줌
vector<char> toPostFix(string on);
// 연산 진행 후 값 출력
char operation(vector<char> on);

int main()
{
    vector<char> postFix;
    int num = 0;
    string input[MAX_INPUT];

    //makeTxtFile();    // operations.txt 생성
        
    cout << "'a','b','c' 와 연산자 '@','#',&' 만 사용가능 / 공백없이 입력 / EOI 입력시 종료" << endl;
    cout << "----- Input -----" << endl;
    while (true)
    {
        cin >> input[num];
        if (input[num] == "EOI" || num == MAX_INPUT)
            break;
        num++;
    }

    cout << endl << "----- Output -----" << endl;


    for (int i = 0; i < num; i++)
    {
        if (checkBalanced(input[i]) == true)
        {
            postFix = toPostFix(input[i]);
            cout << operation(postFix) << endl;
        }
        else
            cout << "Error!" << endl;x
    }
}

/****** function implementation ******/

void makeTxtFile()
{
    ofstream oper;
    oper.open("operations.txt");
    oper << "@\n";
    oper << "a b c\n";
    oper << "b c a\n";
    oper << "c a b\n";
    oper << "#\n";
    oper << "a c b\n";
    oper << "b a c\n";
    oper << "c b a\n";
    oper << "&\n";
    oper << "a a a \n";
    oper << "a b c\n";
    oper << "a c b\n";
    oper.close();
}

bool checkBalanced(string on)
{
    stack<char> check;

    for (int i = 0; i < (int)on.size(); i++)
    {
        switch (on[i])
        {
        case '(' :
        case '{' :
        case '[' :
            check.push(on[i]);
            break;
        case ')':
            if (check.empty() == true || check.top() != '(')
                return false;
            if (check.top() == '(')
                check.pop();
            break;
        case '}':
            if (check.empty() == true || check.top() != '{')
                return false;
            if (check.top() == '{')
                check.pop();
            break;
        case ']':
            if (check.empty() == true || check.top() != '[')
                return false;
            if (check.top() == '[')
                check.pop();
            break;
        default:
            break;
        }
    }
    if (check.empty() == true)
        return true;
    else
        return false;
}

vector<char> toPostFix(string on)
{
    vector<char> postfix;
    stack<char> temp;

    for (int i = 0; i < (int)on.size(); i++)
    {
        switch (on[i])
        {
        case '(':
        case '{':
        case '[':
            temp.push(on[i]);
            break;
        case '@':
        case '#':
            if (temp.empty() != true)
            {
                if (temp.top() == '@' || temp.top() == '#' || temp.top() == '&')
                {
                    postfix.push_back(temp.top());
                    temp.pop();
                }
            }
            temp.push(on[i]);
            break;
        case '&':
            if (temp.empty() != true)
            {
                if (temp.top() == '&')
                {
                    postfix.push_back(temp.top());
                    temp.pop();
                }
            }
            temp.push(on[i]);
            break;
        case 'a':
        case 'b':
        case 'c':
            postfix.push_back(on[i]);
            break;
        case ')':
            while (temp.top() != '(')
            {
                postfix.push_back(temp.top());
                temp.pop();
            }
            temp.pop();
            break;
        case '}':
            while (temp.top() != '{')
            {
                postfix.push_back(temp.top());
                temp.pop();
            }
            temp.pop();
            break;
        case ']':
            while (temp.top() != '[')
            {
                postfix.push_back(temp.top());
                temp.pop();
            }
            temp.pop();
            break;
        default:
            break;
        }
        if(i == (int)on.size() - 1)
            postfix.push_back(temp.top());
    }

    return postfix;
}

char operation(vector<char> on)
{
    stack<char> ch;

    char front, back, result;
    int x = 1, y = 1, depth = 0;
    char data[3][4][4] = { '\0' , }; // txt 내용담은 3차원 배열
    char chr;

    ifstream file("operations.txt"); //data.txt 파일을 읽는다.

    // 파일이 끝나면 peek()는 EOF를 반환
    while (file.peek() != EOF) {
        file.get(chr);
        if (!isspace(chr)) {
            if (chr == '@' || chr == '&' || chr == '#') {
                data[depth][0][0] = chr;
            }
            else {
                data[depth][x++][y] = chr;
                if (x > 3) {
                    x = 1;
                    y++;
                }
                if (y > 3) {
                    y = 1;
                    depth++;
                }
            }
        }
    }

    file.close(); //파일 닫기

    for (size_t i = 0; i < on.size(); i++)
    {

        switch (on[i])
        {
        case 'a':
        case 'b':
        case 'c':
            ch.push(on[i]);
            break;
        case '@':
            back = ch.top();
            ch.pop();
            front = ch.top();
            ch.pop();
            switch (front)
            {
            case 'a':
                switch (back)
                {
                case 'a': ch.push(data[0][1][1]); break;
                case 'b': ch.push(data[0][2][1]); break;
                case 'c': ch.push(data[0][3][1]); break;
                default:
                    break;
                }
                break;
            case 'b':
                switch (back)
                {
                case 'a': ch.push(data[0][1][2]); break;
                case 'b': ch.push(data[0][2][2]); break;
                case 'c': ch.push(data[0][3][2]); break;
                default:
                    break;
                }
                break;
            case 'c':
                switch (back)
                {
                case 'a': ch.push(data[0][1][3]); break;
                case 'b': ch.push(data[0][2][3]); break;
                case 'c': ch.push(data[0][3][3]); break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
            break;

        case '#':
            back = ch.top();
            ch.pop();
            front = ch.top();
            ch.pop();
            switch (front)
            {
            case 'a':
                switch (back)
                {
                case 'a': ch.push(data[1][1][1]); break;
                case 'b': ch.push(data[1][2][1]); break;
                case 'c': ch.push(data[1][3][1]); break;
                default:
                    break;
                }
                break;
            case 'b':
                switch (back)
                {
                case 'a': ch.push(data[1][1][2]); break;
                case 'b': ch.push(data[1][2][2]); break;
                case 'c': ch.push(data[1][3][2]); break;
                default:
                    break;
                }
                break;
            case 'c':
                switch (back)
                {
                case 'a': ch.push(data[1][1][3]); break;
                case 'b': ch.push(data[1][2][3]); break;
                case 'c': ch.push(data[1][3][3]); break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
            break;

        case '&':
            back = ch.top();
            ch.pop();
            front = ch.top();
            ch.pop();
            switch (front)
            {
            case 'a':
                switch (back)
                {
                case 'a': ch.push(data[2][1][1]); break;
                case 'b': ch.push(data[2][2][1]); break;
                case 'c': ch.push(data[2][3][1]); break;
                default:
                    break;
                }
                break;
            case 'b':
                switch (back)
                {
                case 'a': ch.push(data[2][1][2]); break;
                case 'b': ch.push(data[2][2][2]); break;
                case 'c': ch.push(data[2][3][2]); break;
                default:
                    break;
                }
                break;
            case 'c':
                switch (back)
                {
                case 'a': ch.push(data[2][1][3]); break;
                case 'b': ch.push(data[2][2][3]); break;
                case 'c': ch.push(data[2][3][3]); break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }
    }
    result = ch.top();
    return result;
}
