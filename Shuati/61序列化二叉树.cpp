//c风格
class Solution {
public:
    void PreTrav(TreeNode *root,string &s)
    {
       if(!root){
           s+="#,";
           return ;
       }
        s+=to_string(root->val)+",";
        PreTrav(root->left,s);
        PreTrav(root->right,s);
    }
    char* Serialize(TreeNode *root) { 
        string s;
        PreTrav(root,s);
        char* p=new char[s.size()+1];
        strcpy(p,s.c_str());
        return p;
    }
	TreeNode* Deserialize(char *(&str))
	{
	    char *pdot=strchr(str,',');
        if(*(pdot-1)=='#')
        {
            str=pdot+1;
            return NULL;
        }
        TreeNode*root=new TreeNode(strtol(str,&pdot,10));
        str=pdot+1;
        root->left=Deserialize(str);
        root->right=Deserialize(str);
        return root;
	}
};
//C++风格
class Solution {
public:
    void PreTrav(TreeNode *root,string &s)
    {
        if(!root){
            s+="#,";
            return ;
        }
        s+=to_string(root->val)+",";
        PreTrav(root->left,s);
        PreTrav(root->right,s);
    }
    char* Serialize(TreeNode *root) { 
        string str;
        PreTrav(root,str);
        char* p=new char[str.size()+1];
        strcpy(p,str.c_str());
        return p;
    }
	TreeNode* RecurDe(string str, int &st)
	{
		TreeNode *root = NULL;
		int ind = str.find_first_of(',', st);
		if (str[st] == '#') //最后调用的两个一定是两个#号，因为最后叶节点的两个子节点都为空，所以不需要考虑str的结束符，因为在这之前已经停止递归了 
			st = ind + 1;
		else {
			root = new TreeNode(stoi(str.substr(st, ind - st)));
			st = ind + 1;
			root->left = RecurDe(str, st);
			root->right = RecurDe(str, st);
		}
		return root;
	}
	TreeNode* Deserialize(char *(&str))
	{
		int st = 0;
		if (str == NULL)return NULL;
		return RecurDe(string(str), st);
	}
};
