#pragma once
#include <iostream>
#include <string>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

class Book;
class Publisher
{
public:
    std::string name{};

    Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
    }
};

class Stock;
class Book
{
public:
    int id_publisher{};
    std::string title{};
    Wt::Dbo::ptr<Publisher> publisher;
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, id_publisher, "id_publisher");
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "publisher");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
    }
};

class Stock;
class Shop
{
public:
    std::string name{};
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToMany, "shop");
    }
};

class Sale;
class Stock
{
public:
    int id_book{};
    int id_shop{};
    int count{};
    Wt::Dbo::ptr<Book> book;
    Wt::Dbo::ptr<Shop> shop;
    Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, id_book, "id_book");
        Wt::Dbo::field(a, id_shop, "id_shop");
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, book, "book");
        Wt::Dbo::belongsTo(a, shop, "shop");
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
    }
};


class Sale
{
public:
    float price{};
    std::string date_sale{};
    int id_stock{};
    int count{};
    Wt::Dbo::ptr<Stock> stock;


    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, date_sale, "date_sale");
        Wt::Dbo::field(a, id_stock, "id_stock");
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, stock, "stock");
    }
};