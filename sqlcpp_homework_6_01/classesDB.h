#pragma once
#include <iostream>
#include <string>
#include <Wt/Dbo/Dbo.h>


class Publisher
{
public:
	int id;
	std::string name;

    Wt::Dbo::collection<Wt::Dbo::ptr<Book>> book;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, id, "id");
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, book, Wt::Dbo::ManyToOne, "publisher");
    }
};

class Book
{
public:
    int id;
    int id_publisher;
    std::string title;
    Wt::Dbo::ptr<Publisher> publisher;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, id, "id");
        Wt::Dbo::field(a, id_publisher, "id_publisher");
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "publisher");
    }
};

class Shop
{
public:
    int id;
    std::string name;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, id, "id");
        Wt::Dbo::field(a, name, "name");
    }
};

class Stock
{
public:
    int id;
    int id_book;
    int id_shop;
    int count;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, id, "id");
        Wt::Dbo::field(a, id_book, "id_book");
        Wt::Dbo::field(a, id_shop, "id_shop");
        Wt::Dbo::field(a, count, "count");
    }
};


class Sale
{
public:
    int id;
    float price;
    std::string date_sale;
    int id_stock;
    int count;


    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, id, "id");
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, date_sale, "date_sale");
        Wt::Dbo::field(a, id_stock, "id_stock");
        Wt::Dbo::field(a, count, "count");
    }
};