bool Insert(const pair<K,V> _kv)
{
     //插入结点
    if(root == nullptr)
    {
        root=new Node(kv);
        root->_col = BLACK;
        return true;
    }
    Node* parent = nullptr;
    Node* cur = root;
    while(cur)
    {
        if(cur->kv.first < kv.first)
            
        else if(cur->kv.first > kv.first)
        
        else 
            return false;
    }
    cur = new Node(kv);
    cur->_col = RED;
    //父节点连接插入的结点
    if(parent->kv.first < kv.first)
    {
        parent->_right = cur;
        cur->_parent = parent;
    }
    else
    {
        ...
    }
    
    //颜色调整
    //红红相连
    while(parent && parent->_col==RED)
    {
        Node* g = parent->_parent;
        //叔叔在右边
        if(parent == g->_left)
        {
            Node* u = g->_right;
            //红红叔红,变色调整
            if(u && u->_col==RED)
            {
                parent->_col = BLACK;
                u->_col = BLACK;
                g->_col = RED;
                
                cur = g;
                parent = cur->_parent;
            }
            //红红叔非红,旋转调整
            else
            {
                 //红红不齐叔非红,左旋变齐
                 if(cur == parent->_right)
                  { 
                    RotateL(parent);
                    swap(parent,cur);
                  }
                  //红红齐叔非红,右旋+调色   
                  RotateR(g);
                  parent->_col = BLACK;
                  g->_col = RED;
                  
                  break;   
            }//end of  叔非红处理    
        }
        //叔叔在左边
        else
        {
           //...  
        }
       
    }//end of 红红相连
    
        //按规定将其根置为黑 : 防止根为cur情况
        _root->_col = BLACK;
        return true;
}
