#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};


//юнит-тест
TEST_CASE("Checking list", "[List]") {
    List L1;

    SECTION("Проверка пустой список или нет CHECK_FALSE Empty()")
    {
        INFO("Проверка пустой список или нет CHECK_FALSE Empty()");

        //Пустой
        CHECK_FALSE(!L1.Empty());
        L1.PushBack(102);
        //Не пустой
        CHECK_FALSE(L1.Empty());
        L1.PopBack();
        //Пустой
        CHECK_FALSE(!L1.Empty());

    };

    SECTION("Проверка размера списка CHECK Size()")
    {
        INFO("Проверка размера списка");
        //Пустой
        CHECK(L1.Size() == 0);
        L1.PushBack(102);
        //Не пустой
        CHECK(L1.Size() == 1);
        L1.PushBack(102);
        L1.PushBack(103);
        L1.PushBack(104);
        //Не пустой
        CHECK(L1.Size() == 4);
        L1.PopBack();
        //Не пустой
        CHECK(L1.Size() == 3);
        L1.PopBack();
        L1.PopBack();
        L1.PopBack();
        //Пустой
        CHECK(L1.Size() == 0);
    };

    SECTION("Проверка очистки списка CHECK Clear()")
    {
        INFO("Проверка очистки списка CHECK Clear()");

        L1.Clear();
        //Пустой
        CHECK(L1.Size() == 0);
        L1.PushBack(110);
        //Не Пустой
        CHECK(L1.Size() == 1);
        L1.PopBack();
        //Пустой
        CHECK(L1.Size() == 0);
    };
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RU");
    return Catch::Session().run(argc, argv);
}