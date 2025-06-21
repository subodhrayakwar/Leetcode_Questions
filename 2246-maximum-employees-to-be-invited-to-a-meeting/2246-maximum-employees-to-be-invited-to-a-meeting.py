class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        # chain = each employee is seated next to their favorite, first employee isn't favorite of anyone
        # cycle = the first employee in the chain is the favorite of the last employee in the chain
        # group = every employee is seated next to their favorite but the first isn't the favorite of the last
        #         possible when to two employees favorite one another 0->1-><-2<-3

        n = len(favorite) # number of employees

        fav_counter = [0] * n # collect how many times employee f is favorited
        for f in favorite:
            fav_counter[f] += 1

        # employees who have no favorites are the first in a chain, nothing connects to them
        root_employees = deque(emp for emp, fav_count in enumerate(fav_counter) if fav_count == 0)
        chain_lengths = [1] * n # length of chains for each employee, always includes themselves
        while root_employees: 
            root_emp = root_employees.popleft() # get first root for proper chain order
            root_fav = favorite[root_emp]
            chain_lengths[root_fav] = chain_lengths[root_emp] + 1 # add employee and their chain to their favorite
            fav_counter[root_fav] -= 1 # root_fav lost an incoming connection
            if fav_counter[root_fav] == 0: # if no more incoming connections, they become a root
                root_employees.append(root_fav)

        # all employees with fav_count > 0 are in a cycle or group
        # all employees with fav_count == 0 are roots and have been turned into chains

        max_cycle = 0 # full cycle where last favorite = first employee
        sum_groups = 0 # combine groups of happy employees, no connection between groups
        for start_emp, fav_count in enumerate(fav_counter):
            if fav_count == 0: continue # skip if already visited
            fav_counter[start_emp] = 0 # set employee as visited

            cycle_len = 1
            cur_emp = favorite[start_emp]
            while cur_emp != start_emp: # loop until find start employee
                fav_counter[cur_emp] = 0  
                cycle_len += 1
                cur_emp = favorite[cur_emp]

            if cycle_len == 2: # found a group, add chains for both employees to get group length and add to sum group
                sum_groups += chain_lengths[start_emp] + chain_lengths[favorite[start_emp]]
            else: # found a cycle, last employee loops to first employee
                max_cycle = max(max_cycle, cycle_len)

        return max(max_cycle, sum_groups) # most employees is biggest cycle or collection of groups       