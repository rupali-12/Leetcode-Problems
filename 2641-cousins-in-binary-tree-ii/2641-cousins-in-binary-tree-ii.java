class Solution {
    Map<Integer,Integer> map;
    Map<TreeNode,Integer> map2;
    public TreeNode replaceValueInTree(TreeNode root) {
        map = new HashMap<>();
        map2 = new HashMap<>();
        dfs(root, null, 0);
        fillSum(root, null, 0);
        return root;
    }
    
    private void dfs(TreeNode root,TreeNode parent,int c){
        if(root==null){
            return;
        }
        if(parent!=null){
           map2.put(parent,map2.getOrDefault(parent,0)+root.val);
           map.put(c,map.getOrDefault(c,0)+root.val);
        }
        dfs(root.left,root,c+1);
        dfs(root.right,root,c+1);
    }

    private void fillSum(TreeNode root,TreeNode parent,int c){
        if(root==null){
            return;
        }
        root.val = parent==null? 0: (map.get(c)-map2.get(parent));
        fillSum(root.left,root,c+1);
        fillSum(root.right,root,c+1);
    }
}