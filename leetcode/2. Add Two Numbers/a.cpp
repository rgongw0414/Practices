
// Recursive functioun to iterate through and add the nodes of l1, l2
// In every turn, each list pointer is passed as a next pointer

void add_nodes(ListNode* result, ListNode* l1, ListNode* l2, int carryIn) {

    // Check for nullptrs to signal the end of addition
    if (l1 == nullptr && l2 == nullptr) {
        result->val = carryIn; // The last carryIn is added as last step.
        return;
    }
    if (l1 == nullptr) {
        l1 = new ListNode(0);
    }
    if (l2 == nullptr) {
        l2 = new ListNode(0);
    }

    // Extrac the sum and the carryIn
    int sum = carryIn + l1->val + l2->val;
    if (sum >= 10) {
        result->val = sum - 10;
        carryIn = 1;
    }
    else {
        result->val = sum;
        carryIn = 0;
    }

    // if there is still more nodes or a non-zero carryIn assign a new node to the result
    if (l1->next != nullptr || l2->next != nullptr || carryIn != 0) {
        result->next = new ListNode(0);
        ListNode* l1Next = l1->next;
        ListNode* l2Next = l2->next;
        if (!l1) delete l1;  // delete unused nodes, because there are |len(l1) - len(l2)| redundant nodes
        if (!l2) delete l2;  // e.g. l1: [1, 2], l2: [2, 3, 4, 5], there will be 2 redundant nodes with val of 0, for calculating sum of two lists.
        add_nodes(result->next, l1Next, l2Next, carryIn); // Repeat
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Declare the head pointer of the result list
        ListNode* result = new ListNode(0);

        // Returning the result implicitly
        add_nodes(result, l1, l2, 0);
        return result;
    }
};



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // recursion, TC, SC: O(N)
        // return the head of sum list of l1 and l2
        // note that the sum is store at l1 to reuse l1's memory.
        if (!l1) {
            // l1 got NO remaining digits
            if (l2) {
                // l2 got remaining
                return l2; // Return the remaining digits
            }
            return nullptr;
        }
        // here the code is not returned, indicating l1 got remainings digits
        if (l2) {
            // l2 got remaining digits
            l1->val += l2->val; // Add the two digits, and store at l1
        }

        // check carry-in or not
        if (l1->val >= 10) {
            // Carry the one to the next digit
            if (l1->next) {
                l1->next->val++; 
            }
            else {
                l1->next = new ListNode(1); 
            }
            l1->val -= 10;
        }
        
        if (l2) {
            // Repeat the process for the remaining digits
            l1->next = addTwoNumbers(l1->next, l2->next); 
        }
        else {
            l1->next = addTwoNumbers(l1->next, nullptr);
        }
        return l1;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // cleaner code, but worse SC; 
        // Time: O(max(m, n)); 
        // Space: O(max(m, n))
        ListNode* dummyHead = new ListNode(); // dummyHead head of new list
        
        ListNode* curr = dummyHead; // dummyHead->newHead
        int carryIn = 0;
        
        while (l1 != NULL || l2 != NULL) {
            int val1 = (l1)? l1->val: 0; // put 0 if current in nullptr, for calculating sum
            int val2 = (l2)? l2->val: 0;
            
            int sum = val1 + val2 + carryIn;
            if (sum >= 10) {
                sum -= 10;
                carryIn = 1;
            }
            else {
                carryIn = 0;
            }
            
            curr->next = new ListNode(sum);
            curr = curr->next;
            
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        
        if (carryIn == 1) {
            curr->next = new ListNode(1);
        }
        ListNode* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // long code, better SC, for the sack of calculating list sizes. TC: O(3N), SC: O(1)
        // sums up two lists
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        int cnt1 = 0, cnt2 = 0;
        while (curr1) {
            cnt1++;
            curr1 = curr1->next;
        }
        while (curr2) {
            cnt2++;
            curr2 = curr2->next;
        }
        if (cnt1 < cnt2) {
            // let l1 always be the longer list
            swap(l1, l2);
        }
        curr1 = l1;
        curr2 = l2;
        ListNode *prev1 = nullptr; // if carryIn, then create a new node after tail node for it.
        int carryIn = 0; // default carry in for first digit
        while (curr1 and curr2) {
            int digitSum = carryIn + curr1->val + curr2->val;
            if (digitSum >= 10) {
                // use comparison, instead of division, because comparison is faster
                curr1->val = digitSum - 10;
                carryIn = 1;
            }
            else {
                curr1->val = digitSum;
                carryIn = 0;
            }
            // curr1->val = (digitSum) % 10; // store sum result in list1 to save memory
            // carryIn = (digitSum) / 10; // carry in for next digit
            prev1 = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        // sums up the remaining digits in list1
        while (curr1) {
            int digitSum = carryIn + curr1->val;
            if (digitSum >= 10) {
                // use comparison, instead of division, because comparison is faster
                curr1->val = digitSum - 10;
                carryIn = 1;
            }
            else {
                curr1->val = digitSum;
                carryIn = 0;
            }
            prev1 = curr1;
            curr1 = curr1->next;
        }
        if (carryIn) {
            // got carryIn, indicating have to add a new node to tail to store the carry in digit
            prev1->next = new ListNode(carryIn);
        }
        return l1;
    }
};