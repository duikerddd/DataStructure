 bool Erase(const T& data)
        {
            // 如果树为空，删除失败
            if (nullptr == _pRoot)
            return false;
            
            // 查找在data在树中的位置
            PNode pCur = _pRoot;
            PNode pParent = nullptr;
            while (pCur)
            {
                if (data == pCur->_data)
                break;
                else if (data < pCur->_data)
                {
                pParent = pCur;
                pCur = pCur->_pLeft;
                }
                else
                {
                pParent = pCur;
                pCur = pCur->_pRight;
                }
            }
            // data不在二叉搜索树中吗，无法删除
            if (nullptr == pCur)
            return false;
            
            // 分以下情况进行删除
            if (nullptr == pCur->_pRight)
            {
            // 当前节点只有左孩子或者左孩子为空---可直接删除
                if(nullptr != pCur->_pLeft)
                {
                    pParent->_pLeft = pCur->_pLeft;
                }
                delete pCur;
            }
            else if (nullptr == pCur->_pRight)
            {
            // 当前节点只有右孩子---可直接删除
                pParent->_pRight = pCur->_pRight;
                delete pCur;
            }
            else
            {
            //两个孩子都有
            //找左子树最大或者右子树最小,然后交换,删除
            pMax = pCur->pLeft;
            //注意要置空删除的节点
            pMP = pCur;
            while(nullptr != pMax->pRight)
            {
              pMP = pMax;
              pMax =  pMax->pRight;
            }
            pCur->data = pMax->data;
            pMP->pLeft = nullptr;
            delete pMax;
            }
        return true;
        }
