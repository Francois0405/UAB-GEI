template<class T1, int N>
class VectorSimple {
public:
    VectorSimple() {}  // constructor vacío
    T1 get(int pos) { return arr[pos]; }
    void set(int pos, T1 val) { arr[pos] = val; }
private:
    T1 arr[N];
};