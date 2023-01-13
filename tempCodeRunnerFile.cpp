rootToLeafPathsSumToK(root->left, k - root->data, path);
    rootToLeafPathsSumToK(root->right, k - root->data, path);