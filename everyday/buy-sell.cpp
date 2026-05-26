#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
using namespace std;

struct Order {
    int id;
    char side;   // 'B' or 'S'
    int price;
    int qty;
};

void processOrders(const vector<Order>& orders) {
    map<int, queue<Order>, greater<int>> buyBook;
    map<int, queue<Order>> sellBook;

    long long buyRemain = 0;
    long long sellRemain = 0;

    for (auto order : orders) {
        if (order.side == 'B') {
            // 买单匹配最低卖价
            while (order.qty > 0 && !sellBook.empty()) {
                auto it = sellBook.begin(); // 最低卖价

                if (order.price < it->first) {
                    break;
                }

                auto& q = it->second;
                Order& sell = q.front();

                int tradeQty = min(order.qty, sell.qty);
                int tradePrice = sell.price; // 挂单方价格

                cout << order.id << " "
                     << sell.id << " "
                     << tradePrice << " "
                     << tradeQty << endl;

                order.qty -= tradeQty;
                sell.qty -= tradeQty;

                if (sell.qty == 0) {
                    q.pop();
                }

                if (q.empty()) {
                    sellBook.erase(it);
                }
            }

            // 没成交完，挂到买单簿
            if (order.qty > 0) {
                buyRemain += order.qty;
                buyBook[order.price].push(order);
            }
        } else {
            // 卖单匹配最高买价
            while (order.qty > 0 && !buyBook.empty()) {
                auto it = buyBook.begin(); // 最高买价

                if (order.price > it->first) {
                    break;
                }

                auto& q = it->second;
                Order& buy = q.front();

                int tradeQty = min(order.qty, buy.qty);
                int tradePrice = buy.price; // 挂单方价格

                cout << buy.id << " "
                     << order.id << " "
                     << tradePrice << " "
                     << tradeQty << endl;

                order.qty -= tradeQty;
                buy.qty -= tradeQty;

                if (buy.qty == 0) {
                    q.pop();
                }

                if (q.empty()) {
                    buyBook.erase(it);
                }
            }

            // 没成交完，挂到卖单簿
            if (order.qty > 0) {
                sellRemain += order.qty;
                sellBook[order.price].push(order);
            }
        }
    }

    // 注意：上面的 buyRemain / sellRemain 在成交时没有扣减
    // 所以最后更稳妥的方式是重新遍历订单簿统计

    buyRemain = 0;
    sellRemain = 0;

    for (auto& [price, q] : buyBook) {
        auto tmp = q;
        while (!tmp.empty()) {
            buyRemain += tmp.front().qty;
            tmp.pop();
        }
    }

    for (auto& [price, q] : sellBook) {
        auto tmp = q;
        while (!tmp.empty()) {
            sellRemain += tmp.front().qty;
            tmp.pop();
        }
    }

    cout << "BUY_REMAIN " << buyRemain << endl;
    cout << "SELL_REMAIN " << sellRemain << endl;
}

int main() {
    int n;
    cin >> n;

    vector<Order> orders(n);

    for (int i = 0; i < n; i++) {
        cin >> orders[i].id
            >> orders[i].side
            >> orders[i].price
            >> orders[i].qty;
    }

    processOrders(orders);

    return 0;
}