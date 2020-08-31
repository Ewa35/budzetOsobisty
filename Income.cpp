#include "Income.h"

void Income::setUserId (int newUserId) {
    userId=newUserId;
}
void Income::setId (int newId) {
    id=newId;
}
void Income::setIncomeCategory (string newIncomeCategory) {
    category=newIncomeCategory;
}
void Income::setDate (int newDate) {
    date=newDate;
}
void Income::setValue (double newValue) {
    value=newValue;
}

int Income::getUserId() {
    return userId;
}
int Income::getId() {
    return id;
}
string Income::getIncomeCategory() {
    return category;
}
int Income::getDate() {
    return date;
}
double Income::getValue() {
    return value;
}
