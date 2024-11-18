#include <iostream>
#include <vector>

template <class T >
class Table
{
private:
    std::vector<std::vector<T> > tab_;

public:
    Table(int row, int col)
    {
        std::vector<std::vector<T> >  tab1_(row, std::vector<T>(col));

        this->tab_ = tab1_;
    }

    T get_element(int row, int col)
    {
        return tab_[row][col];
    }

    T get_const_element(int row, int col) const
    {
        return tab_[row][col];
    }
    void set_element(int row, int col, T element)
    {
        tab_[row][col] = element;
    }
    std::vector<T>& operator[](int index)
    {
        return tab_[index];
    }

    ~Table()
    {
        
    }
};

int main()
{
	auto t = Table<int>(2, 3);
	t[0][0] = 1;
    t[1][2] = 10;
    std::cout << t[0][0] << std::endl;
    std::cout << t[1][2] << std::endl;

    t.set_element(0, 0, 4);
    std::cout << t.get_const_element(0, 0) << std::endl;
    std::cout << t.get_element(0, 0) << std::endl;

    std::cout << t[0][0] << std::endl;

	return EXIT_SUCCESS;
}