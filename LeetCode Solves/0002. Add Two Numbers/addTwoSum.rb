# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}

class ListNode
  attr_accessor :val, :next
  def initialize(val = 0, _next = nil)
    @val = val
    @next = _next
  end
end

def numberMaker(l)
    number = 0
    count = 0
    while l != nil
        number += l.val * (10 ** count)
        count += 1
        l = l.next
    end
    return number
end

def reverseNodeMaker(number)
    head = ListNode.new
    current = head
    number = number.to_s.reverse
    number.each_char do |char|
        current.next = ListNode.new(char.to_i)
        current = current.next
    end
    return head.next
end

def add_two_numbers(l1, l2)
    head = ListNode.new
    number = numberMaker(l1) + numberMaker(l2)
    # puts number # for debugging
    head = reverseNodeMaker(number)
    # puts head.val # for debugging

    return head
end

l1 = ListNode.new(2, ListNode.new(4, ListNode.new(3)))
l2 = ListNode.new(5, ListNode.new(6, ListNode.new(4)))

add_two_numbers(l1, l2)