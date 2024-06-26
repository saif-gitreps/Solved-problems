// had to use Kahn algo but for sorting.
type Queue struct {
    items []int
}

func (q *Queue) Push(item int) {
    q.items = append(q.items, item)
}

func (q *Queue) Pop() {
    if len(q.items) == 0 {
        return;
    }
    q.items = q.items[1:];
}

func (q *Queue) IsEmpty() bool {
    return len(q.items) == 0;
}

func (q *Queue) Front() int{
    return q.items[0];
}

func findOrder(n int, a [][]int) []int {
    adj := make([][] int, n);
    
    for i := 0; i < len(a); i++ {
        adj[a[i][1]] = append(adj[a[i][1]], a[i][0]);
    }

    indeg := make([] int, n);

    for i := 0; i < n; i++ {
        for _, child := range adj[i] {
            indeg[child]++
        }
    }

    q := Queue{};

    for i := 0; i < n; i++ {
        if (indeg[i] == 0){
            q.Push(i);
        }
    }

    var ans []int;

    for !q.IsEmpty() {
        node := q.Front();
        q.Pop();
        ans = append(ans, node);
        // count++;

        for _, child := range(adj[node]) {
            indeg[child]--;
            if indeg[child] == 0 {
                q.Push(child);
            }
        }
    }

    if len(ans) == n {
        return ans;
    } else {
        return nil;
    }
}


// more optimised solution, we calculate the indegree right in the first for loop.


func findOrder(numCourses int, prerequisites [][]int) []int {
    adjs := make([][]int, numCourses)
    ins := make([]int, numCourses)
    for _, preq := range prerequisites {
        adjs[preq[1]] = append(adjs[preq[1]], preq[0])
        ins[preq[0]]++
    }
    q := list.New()
    for i, in := range ins {
        if in == 0 {
            q.PushBack(i)
        }
    }
    courses := make([]int, 0, numCourses)
    for q.Len() > 0 {
        front := q.Front()
        q.Remove(front)
        course := front.Value.(int)
        courses = append(courses, course)
        for _, adj := range adjs[course] {
            ins[adj]--
            if ins[adj] == 0 {
                q.PushBack(adj)
            }
        }
    }
    if len(courses) != numCourses {
        return nil
    }
    return courses
}
