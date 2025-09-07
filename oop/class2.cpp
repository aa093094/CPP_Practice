#include <iostream>

class Date {
    private:
    int year_;
    int month_;
    int day_;

    public:
    void SetDate(int year, int month, int date) {
        year_ = year;
        month_ = month;
        day_ = date;
    }
    void AddDay(int inc) {
        if (month_ < 7) {
            if (month_ % 2 == 0) {
                if (month_ == 2 && (day_ + inc) > 29) {
                    month_++;
                    day_ = day_ + inc - 29;
                } else if (month_ != 2 && (day_ + inc) > 30) {
                    month_++;
                    day_ = day_ + inc - 30;
                } else {
                    day_ = day_ + inc;
                }
            } else {
                if ((day_ + inc) > 31) {
                    month_++;
                    day_ = day_ + inc - 31;
                } else {
                    day_ = day_ + inc;
                }
            }
        } else {
            if (month_ % 2 == 0) {
                if ((day_ + inc) > 31) {
                    month_++;
                    day_ = day_ + inc - 31;
                } else {
                    day_ = day_ + inc;
                }
            } else {
                if ((day_ + inc) > 30) {
                    month_++;
                    day_ = day_ + inc - 30;
                } else {
                    day_ = day_ + inc;
                }
            }
        }
    }
    void AddMonth(int inc) {
        if (month_ + inc > 12) {
            year_++;
            month_ = month_ + inc - 12;
        } else {
            month_ += inc;
        }
    }
    void AddYear(int inc) {
        year_ += inc;
    }
    void ShowDate() {
        std::cout << "YYYY/MM/DD : " << year_ << "/" << month_ << "/" << day_ << std::endl; 
    }
};

int main() {
    Date date;
    date.SetDate(2025, 9, 27);
    date.AddDay(5);
    date.AddMonth(4);
    date.AddYear(3);
    date.ShowDate();

    return 0;
}