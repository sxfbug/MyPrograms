#include"graph.hpp"

vector<int> cri_path(Matrix_DirectedGraph_Weighted &x)
{
    //init
    int n=x.getsize();
    vector<vector<int>> graph=x.getgraph();
    vector<int> final;

    vector<int> ve(n,0);
    vector<int> vl(n,0);
    //元组的三个int分别是，数值，弧尾，弧头
    vector<tuple<int,int,int>> ee;
    vector<tuple<int,int,int>> el;

    //先计算结点的最早和最迟完成时间
    //需要前驱和后继数组辅助? 其实直接遍历拓扑序列就可以
    vector<int> topo=Topo(x);

    //处理topo的特殊情况
    if (topo.size()==0)
    {
        cout<<"topo is null";
        return vector<int>();
    }
    if (topo.size()==1)
    {
        return vector<int>();
    }
    
    //计算事件最早发生事件ve
    
    //首事件的最早发生时间是0
    ve[topo[0]]=0;

    //时间复杂度已经n^2了
    //从第二个事件开始
    //target是当前正在求解的topo序列中的元素index
    int idx=1;

    cout<<"topo=";
    pri_vec(topo);
    for (; idx < topo.size(); idx++)
    {
        int target = topo[idx];
       
        //在topo中，遍历所有在目标元素之前的元素，寻找是否有可达路径（是目标的前驱）
        //如有，计算其路径长度，放到临时数组里
        //遍历完成后，再遍历该数组，寻找最大值
        vector<int> dist_set;
        int idx2=0;
        //j是topo序列的元素
        for (; idx2 < idx; idx2++)
        {
            int j = topo[idx2];
            //有到达target的路径
            if (graph[j][target]!=0)
            {
                dist_set.push_back(ve[j]+graph[j][target]);
            }
        }
        
        
        //遍历结束后，比较大小，添加最大值
        
        
        ve[target]=max(dist_set);
        
    }
    cout<<"ve:";
    pri_vec(ve);
    
    
    //计算事件最迟完成时间vl

    //最后一个topo元素的vl和ve相同
    vl[topo.back()]=ve[topo.back()];
    //cout<<"last vl"<<vl[topo.back()];

    //从倒数第二个元素开始，迭代
    //寻找topo在该元素后面，所有有出边相连的后继，计算长度，求最小值
    for (int i = topo.size()-2; i >=0; i--)
    {
        int target=topo[i];
        //所有后继的值的集合
        vector<int> dist_set;
        for (int j = topo.size()-1; j>i; j--)
        {
            int back=topo[j];
            if (graph[target][back]!=0)
            {
                dist_set.push_back(vl[back]-graph[target][back]);
            }
            
        }
        
       if (!dist_set.empty()) {
            vl[target] = min(dist_set);
        } else {
            vl[target] = ve[target]; // 没有后继，vl等于ve
        }
        
    }
    cout<<"vl:";
    pri_vec(vl);


    //每个活动的最早发生时间ee
    //就是这个事件的最早发生时间
    //边的数量，不能确定
    //每个活动的最晚发生时间
    //由事件最晚发生时间，减去该活动的边权值

    
    for (int i = 0; i < n; i++)
    {
        int head=topo[i];
        for (int j = 0; j<n; j++)
        {
            int tail=topo[j];
            //存在边
            if (graph[head][tail]!=0)
            {
                tuple<int,int,int> edge_ee(ve[head],head,tail);
                tuple<int,int,int> edge_el(vl[tail]-graph[head][tail],head,tail);
                //同步计算ee和el
                ee.push_back(edge_ee);
                el.push_back(edge_el);
            }
            
        }
        
    }
    cout<<"ee:";
    pri_vec(ee);

    cout<<"el:";
    pri_vec(el);

    //计算ee和el的差值，从而得出关键路径
    for (int i = 0; i < ee.size(); i++)
    {
        if (get<0>(ee[i])-get<0>(el[i])==0)
        {
            //把弧头指向的结点添加进来
            final.push_back(get<1>(ee[i]));
            //也添加弧尾，后面再去重
            final.push_back(get<2>(ee[i]));
        }
        
    }
    
    vector<int> unique_final;
    
    pri_vec(final);
    //去重，暴力算法，遍历两次

    int head=-1,tail=-1;
    //标记是否需要添加到unique final后面
    bool have_visited=false;
    for (int i = 0; i < final.size(); i++)
    {
        
        if (have_visited)
        {
            have_visited=false;
            tail=final[i];
            unique_final.push_back(final[i]);
            continue;
            /* code */
        }
        
        if (final.size()<2)
        {
            cout<<"final size too small";
            break;
        }
        
        if (head==-1)
        {
            head=final[i];
            tail=final[i+1];
            i+=1;
            unique_final.push_back(head);
            unique_final.push_back(tail);
        }
        //当前序列的尾结点，和下一个弧的起始结点一样
        //还要判断当前i是否是偶数，如果是，才是新的弧的弧头
        //添加下一个元素
        if (tail==final[i] && i<final.size()-1 && i%2==0)
        {   
            have_visited=true;
        }

        //找到汇点了，可以break
        if (unique_final.back()==topo.back())
        {
            break;
        }
        
        
        
        
    }
    
    
    cout<<"final:";
    pri_vec(unique_final);
    

    

    return unique_final;
}