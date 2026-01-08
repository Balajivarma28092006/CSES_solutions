#include <iostream>
#include <vector>

#define ll long long

void Ans(int n){
    ll sum = (1ll * n * (1ll * n + 1)) / 2;
    if(sum % 2 != 0){
        std::cout << "NO\n";
        return;
    } else {
        std::vector<int>set1;
        std::vector<int> set2;
        std::vector<bool> visited(n + 1, false);

        ll set1_sum = 0;
        ll max_element = n;
        ll total_sum = sum / 2;

        while(set1_sum < total_sum){
            ll remaining_sum = total_sum - set1_sum;
            if(remaining_sum > max_element){
                set1.push_back(max_element);
                visited[max_element] = true;
                set1_sum += max_element;
                max_element--;
            } else {
                set1.push_back(remaining_sum);
                visited[remaining_sum] = true;
                set1_sum = total_sum;
                
            }
        }
        for(int i = 1; i <= n; i++){
            if(visited[i] != true){
                set2.push_back(i);
            }
        }

        std::cout << set1.size() << "\n";
        for(auto& v: set1){
            std::cout << v << " ";
        }
        std::cout << "\n";

        std::cout << set2.size() << "\n";
        for(auto& v: set2){
            std::cout << v << " ";
        }
    }
}

void method2(int n){
    ll sum = (1ll * n * (1ll * n + 1)) / 2;
    if(sum % 2 != 0){
        std::cout << "NO\n";
        return;
    } else {
        std::cout << "YES\n";
        std::vector<int>set1;
        std::vector<int> set2;
        ll ans = sum / 2;
        for(int i = n; i >= 1 ; i--){
            if(i <= ans){
                set1.push_back(i);
                ans -= i;
            } else {
                set2.push_back(i);
            }
        }
        std::cout << set1.size() << "\n";
        for(auto& v: set1){
            std::cout << v << " ";
        }
        std::cout << "\n";

        std::cout << set2.size() << "\n";
        for(auto& v: set2){
            std::cout << v << " ";
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    method2(n);
}