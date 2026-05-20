#ifndef MANAGERRESTAURANT_H
#define MANAGERRESTAURANT_H

class ManagerRestaurant{
    ManagerRestaurant()=default;
    ManagerRestaurant(const ManagerRestaurant &mr)=delete;
    ManagerRestaurant & operator=(const ManagerRestaurant & mr)=delete;

    public:
    static ManagerRestaurant & getInstance();
    void run();
};

#endif
