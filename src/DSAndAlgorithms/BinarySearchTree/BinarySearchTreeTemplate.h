#ifndef BINARYSEARCHTREETEMPLATE_H_
#define BINARYSEARCHTREETEMPLATE_H_

#include <iostream>

template<class T>
struct Node
{
   T value;
   Node *left;
   Node *right;

   Node(T val)
   {
      this->value = val;
      this->left = nullptr;
      this->right = nullptr;
   }

   Node(T val,
      Node<T>left,
      Node<T>right)
   {
      this->value = val;
      this->left = left;
      this->right = right;
   }
};

template<class T>
class BST
{

private:
   Node<T>*root;

   void addHelper(Node<T>*root,
      T val)
   {
      if (root->value > val)
      {
         if (!root->left)
         {
            root->left = new Node<T>(val);
         }
         else
         {
            addHelper(root->left, val);
         }
      }
      else
      {
         if (!root->right)
         {
            root->right = new Node<T>(val);
         }
         else
         {
            addHelper(root->right, val);
         }
      }
   }

   void printHelperInOrderTraversal(Node<T>*root)
   {
      if (root)
      {
         printHelperInOrderTraversal(root->left);
         std::cout << root->value << ' ';
         printHelperInOrderTraversal(root->right);
      }
   }

   void printHelperPreOrderTraversal(Node<T>*root)
   {
      if (root)
      {
         std::cout << root->value << ' ';
         printHelperPreOrderTraversal(root->left);
         printHelperPreOrderTraversal(root->right);
      }
   }

   void printHelperPostOrderTraversal(Node<T>*root)
   {
      if (root)
      {
         printHelperPostOrderTraversal(root->left);
         printHelperPostOrderTraversal(root->right);
         std::cout << root->value << ' ';
      }
   }

   int nodesCountHelper(Node<T>*root)
   {
      if (!root)
         return 0;
      else
         return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
   }

   int heightHelper(Node<T>*root)
   {
      if (!root)
         return 0;
      else
         return 1 + std::max(heightHelper(root->left), heightHelper(root->right));
   }

   void printMaxPathHelper(Node<T>*root)
   {
      if (!root)
         return;
      std::cout << root->value << ' ';
      if (heightHelper(root->left) > heightHelper(root->right))
      {
         printMaxPathHelper(root->left);
      }
      else
      {
         printMaxPathHelper(root->right);
      }
   }

   bool deleteValueHelper(Node<T>* parent,
      Node<T>* current,
      T value)
   {
      if (!current)
         return false;
      if (current->value == value)
      {
         if (current->left == NULL || current->right == NULL)
         {
            Node<T>* temp = current->left;
            if (current->right)
               temp = current->right;
            if (parent)
            {
               if (parent->left == current)
               {
                  parent->left = temp;
               }
               else
               {
                  parent->right = temp;
               }
            }
            else
            {
               this->root = temp;
            }
         }
         else
         {
            Node<T>* validSubs = current->right;
            while (validSubs->left)
            {
               validSubs = validSubs->left;
            }
            T temp = current->value;
            current->value = validSubs->value;
            validSubs->value = temp;
            return deleteValueHelper(current, current->right, temp);
         }
         delete current;
         return true;
      }
      return deleteValueHelper(current, current->left, value) || deleteValueHelper(current, current->right, value);
   }

public:
   void add(T val)
   {
      if (root)
      {
         this->addHelper(root, val);
      }
      else
      {
         root = new Node<T>(val);
      }
   }

   void print()
   {

      std::cout << "InOrderTraversal\n";
         printHelperInOrderTraversal(this->root); 
         std::cout<< std::endl;

      std::cout << "PostOrderTraversal\n" ;
         printHelperPostOrderTraversal(this->root);
      std::cout<< std::endl;

      std::cout << "PreOrderTraversal\n" ;
         printHelperPreOrderTraversal(this->root);
      std::cout<< std::endl;

   }

   int nodesCount()
   {
      return nodesCountHelper(root);
   }

   int height()
   {
      return heightHelper(this->root);
   }

   void printMaxPath()
   {
      printMaxPathHelper(this->root);
   }

   bool deleteValue(T value)
   {
      return this->deleteValueHelper(NULL, this->root, value);
   }
};

#endif


//#include "DSAlgorithms/BinarySearchTree/BinarySearchTreeTemplate.h"
//
//int main() {
//   BST<int> *bst = new BST<int>();
//
//   bst->add(1);
//   bst->add(2);
//   bst->add(5);
//   bst->add(3);
//   bst->add(6);
//   bst->add(4);
//
//   bst->print();
//
//   std::cout<<std::endl;
//   std::cout<<"Nodes count: "<<bst->nodesCount()<<std::endl;
//
//   std::cout<<"Height: "<<bst->height() <<std::endl;
//
//   std::cout<<"Max path: ";
//   bst->printMaxPath();
//   std::cout<<std::endl;
//
//
//
//   //bst->deleteValue(11);
//   //std::cout<<"11 removed: ";
//   //bst->print();
//   //std::cout<<std::endl;
//   //std::cout<<"1 removed: ";
//   //bst->deleteValue(1);
//   //bst->print();
//   //std::cout<<std::endl;
//   //std::cout<<"-1 removed: ";
//   //bst->deleteValue(-1);
//   //bst->print();
//   //std::cout<<std::endl;
//   //std::cout<<"6 removed: ";
//   //bst->deleteValue(6);
//   //bst->print();
//   //std::cout<<std::endl;
//   //std::cout<<"-10 removed: ";
//   //bst->deleteValue(-10);
//   //bst->print();
//   //std::cout<<std::endl;
//   //std::cout<<"100 removed: ";
//   //bst->deleteValue(100);
//   //bst->print();
//   //std::cout<<std::endl;
//
//
//   return 0;
//}
