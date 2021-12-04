#include <iostream>
using namespace std;

struct node{
    long long val;
    node * next;
    node * prev;
};

struct list{
    private:
        node * cur;
        node * front;
    public:
    long long l_size = 0;

    list(){
        cur = front = NULL;
    }

    long long size(){
        return l_size;
    }

    bool empty(){
        return l_size == 0;
    }

    void exit(){
        cout << "bye" << endl;
    }

    void show_front(){
        if(front != NULL){
            cout << front->val << endl;
        }else{
            cout << "error" << endl;
        }
    }

    void show_back(){
        if(cur != NULL){
            cout << cur->val << endl;
        }else{
            cout << "error" << endl;
        }
    }

    void push_front(long long n){
        node * item = new node();
        item->val = n;
        item->prev = item->next = NULL;
        if(front == NULL and l_size == 0){
            cur = front = item;
        }else{
            item->next = front;
            front->prev = item;
            front = item;
        }
        l_size++;
    }

    void push_back(long long n){
        node * item = new node();
        item->val = n;
        item->prev = item->next = NULL;
        if(cur == NULL and l_size == 0){
            cur = front = item;
        }else{
            item->prev = cur;
            cur->next = item;
            cur = item;
        }
        l_size++;
    }

    int pop_front(){
        if(front != NULL){
            int ans = front->val;
            front = front->next;
            if(front == NULL){
                cur = NULL;
            }else{
                front->prev = NULL;
            }
            l_size--;
            return ans;
        }else{
            cout << "error" << endl;
        }
    }
    
    int pop_back(){
        if(cur != NULL){
            int ans = cur->val;
            cur = cur->prev;
            if(cur == NULL){
                front = NULL;
            }else{
                cur->next = NULL;
            }
            l_size--;
            return ans;
        }else{
            cout << "error" << endl;
        }
    }

    void clear(){
        while(front != NULL and cur != NULL){
            cur = cur->prev;
            if(cur == NULL){
                front = NULL;
            }
            l_size--;
        }
        cout << "ok" << endl;
    }
    void swap(node * cur, node * prev){
        int val = cur->val;
        cur->val = prev->val;
        prev->val = val;
    }
    void sort_by_val(){
        node * temp = front, * index = NULL;
        if(front == NULL){
            return;
        }else{
            while(temp != NULL){
                index = temp->next;
                while(index != NULL){
                    if (temp->val > index->val){
                        swap(temp,index);
                    }
                    index = index->next;
                }
                temp = temp->next;
            }
        }
    }

    void print(){
        node * temp = front;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
};

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j <= r - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main(){
    list l;
    int n; cin >> n;
    int a[n];
    for(int i = 0 ; i < n; ++i){
        //cin >> a[i];
        int k; cin >> k;
        l.push_back(k);
    }
    /*
    quickSort(a, 0, n - 1);
    for(int i = 0 ; i < n; ++i){
        l.push_back(a[i]);
    }*/
    l.sort_by_val();
    int ans = 0;
    while(l.size() != 1){
        int f = l.pop_front();
        int s = l.pop_front();
        int temp = f + s;
        l.push_front(temp);
        l.sort_by_val();
        ans+=temp;
    }
    cout << ans;
    }
