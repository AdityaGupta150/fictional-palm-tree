/*Leaving it for now and all*/

#include <iostream>
#include <stack>
#include <string>
#include <string_view>
#include "util/converters.hpp"
#include <variant>

using namespace std;

struct node;	//forward declaration, since both node_dtype and node depend on each other
enum class Type
{
	OPR,	// operation (function<_opRetStruct(node*,node*)>)
	NUM,	// numeric (float)
	EXPR,	// expression (string)
};

/*A node can contain one of those Type types :D*/

typedef std::variant<float, std::string> fs_var;
typedef struct{
	bool isRecommended{false};	// it is recommended to replace root node content, with evaluated only when both leaves had same `type`, for eg. leaving "a" and 14 in two different nodes, than to have it totally as string ie. "a+14"
	fs_var data;
	Type type;
} _opRetStruct;	// only for returning, (it is simply a variant node_dtype without the function, since these add subtract etc functions won't return std::function (ie. it won't return an operation))
typedef std::variant<float, std::string, std::function<_opRetStruct(node*, node*)>> node_dtype;

struct node{
	node_dtype data;	// the variable names, and expressions are stored as string
	Type type;

	node *left, *right;
};

_opRetStruct add(node* one, node* two){
	_opRetStruct retVal;
	retVal.isRecommended = one->type != Type::OPR && (one->type == two->type);



	return retVal;
}

_opRetStruct subtract(node* one, node* two){
	_opRetStruct retVal;
	retVal.isRecommended = one->type != Type::OPR && (one->type == two->type);



	return retVal;
}

_opRetStruct multiply(node* one, node* two){
	_opRetStruct retVal;
	retVal.isRecommended = one->type != Type::OPR && (one->type == two->type);



	return retVal;
}

_opRetStruct divide(node* one, node* two){
	_opRetStruct retVal;
	retVal.isRecommended = one->type != Type::OPR && (one->type == two->type);



	return retVal;
}

void executeOpr(node* root, const node* left, const node* right, bool force = false){	// when force = false, then the root will only be updated is _opRetStruct::isRecommended is true

}

class expTree{
	stack< node* > bucket;  // temporary bucket to use for creating the expression tree

	node* root{ nullptr };

	public:
		void createTree( string_view infix ){
			// work here
			string postfix{ util::converter::inToPost(infix) };

			while ( !this->bucket.empty() )
			{
				this->bucket.pop();
			}



		}

		expTree() = default;

		expTree( string_view infix ){
			this->createTree(infix);
		}

		~expTree(){	// bfs
			if ( !root )    return;

			stack< node* > tmpStack;
			tmpStack.push( this->root );

			while ( !tmpStack.empty() )
			{
				if( tmpStack.top()->left ){
					tmpStack.push(tmpStack.top()->left);
				}
				if( tmpStack.top()->right ){
					tmpStack.push(tmpStack.top()->right);
				}

				delete tmpStack.top();
				tmpStack.pop();
			}
			
		}
};

int main(){
}