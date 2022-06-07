//https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ret_node = nullptr;

		int carry = 0;
		ListNode* current_node = nullptr;
		do {
			if (current_node != nullptr) {
				current_node->next = new ListNode();
				current_node = current_node->next;
			}
			else {
				ret_node = current_node = new ListNode();
			}

			current_node->val += carry;
			current_node->val += (l1 == nullptr) ? 0 : l1->val;
			current_node->val += (l2 == nullptr) ? 0 : l2->val;
			carry = current_node->val / 10;
			current_node->val %= 10;
			l1 = l1 == nullptr? nullptr : l1->next;
			l2 = l2 == nullptr? nullptr : l2->next;
		} while (l1 != nullptr || l2 != nullptr);
		if (carry == 1) {
			current_node->next = new ListNode();
			current_node = current_node->next;
			current_node->val = carry;
		}
		return ret_node;
	}
};
