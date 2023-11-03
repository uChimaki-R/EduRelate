#include <iostream>
using namespace std;

class Matrix
{
public:
    int row, col, **p;

    // 构造函数
    Matrix()
    {
        row = 0;
        col = 0;
        p = NULL;
    }

    // 初始化row和col，分配矩阵数组空间
    void init(int r, int c)
    {
        row = r;
        col = c;
        p = new int *[row];
        for (int i = 0; i < row; i++)
        {
            p[i] = new int[col];
        }
    }

    // 初始化矩阵数组数据
    void fillin(int x, int y, int val)
    {
        p[x][y] = val;
    }

    // 重载运算符'+'
    Matrix operator+(const Matrix &mt)
    {
        Matrix ans;
        ans.init(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int val = p[i][j] + mt.p[i][j];
                ans.fillin(i, j, val);
            }
        }
        return ans;
    }

    // 打印输出函数
    void print()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
    }

    // 析构函数
    ~Matrix()
    {
        if (p)
        {
            for (int i = 0; i < row; i++)
            {
                delete[] p[i];
            }
            delete[] p;
        }
    }
};

void init(Matrix &mt1, Matrix &mt2)
{
    int row, col;
    cout << "row:";
    cin >> row;
    cout << "col:";
    cin >> col;

    mt1.init(row, col);
    mt2.init(row, col);

    cout << "There first matrix:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int val;
            cin >> val;
            mt1.fillin(i, j, val);
        }
    }

    cout << "There second matrix:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int val;
            cin >> val;
            mt2.fillin(i, j, val);
        }
    }
}

void test()
{
    Matrix mt1, mt2;
    init(mt1, mt2);
    cout << "The sum matrix:" << endl;
    Matrix sum = mt1 + mt2;
    sum.print();
}

int main()
{
    test(); // 用调用函数测试析构函数正确性
    return 0;
}