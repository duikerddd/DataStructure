/ 因为关联式容器中存储的是<key, value>的键值对，因此
// k为key的类型，
// ValueType: 如果是map，则为pair<K, V>; 如果是set，则为k
// KeyOfValue: 通过value来获取key的一个仿函数类
template<class K, class ValueType, class KeyOfValue>
class RBTree
{
typedef RBTreeNode<ValueType> Node;
typedef Node* PNode;
public:
typedef RBTreeIterator<ValueType, ValueType*, ValueType&> Iterator;
public:
RBTree();
~RBTree()
/////////////////////////////////////////////////////////////////////
// Iterator
Iterator Begin(){ return Iterator(_pHead->_pLeft);}
Iterator End(){ return Iterator(_pHead);}
//////////////////////////////////////////////////////////////////
// Modify
V& operator[](const K& key){
    return (*(_rb.insert(make_pair(key,V())).first)).second
}
// 将红黑树中的节点清空
void Clear();
Iterator Find(const K& key);
//////////////////////////////////////////////////////////////////
// capacity
size_t Size()const;
bool Empty()const;
// ……
private:
PNode _pHead;
size_t _size; // 红黑树中有效节点的个数
};
