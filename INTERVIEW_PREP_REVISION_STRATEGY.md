# 🎯 90-Day FAANG Interview Preparation - Revision Strategy

> **Target:** Senior Engineer → Staff Software Engineer  
> **Duration:** Feb 9 - May 9, 2026 (90 Days)  
> **Daily Commitment:** 4-5 hours

---

## 📚 The Science of Retention

### The Forgetting Curve (Ebbinghaus)
Without revision, you forget:
- **20 minutes:** 42% forgotten
- **1 hour:** 56% forgotten  
- **1 day:** 66% forgotten
- **1 week:** 75% forgotten
- **1 month:** 79% forgotten

### The Solution: Spaced Repetition + Active Recall

```
┌─────────────────────────────────────────────────────────┐
│  OPTIMAL REVISION INTERVALS                             │
├─────────────────────────────────────────────────────────┤
│  Day 0    →  Learn new concept                          │
│  Day 1    →  First revision (within 24 hours) ⭐        │
│  Day 3    →  Second revision                            │
│  Day 7    →  Third revision                             │
│  Day 14   →  Fourth revision                            │
│  Day 30   →  Fifth revision (move to long-term memory)  │
└─────────────────────────────────────────────────────────┘
```

---

## 🧠 Core Revision Techniques

### 1. **Active Recall** (Most Effective)
Don't re-read. **Test yourself.**
- Close notes, write what you remember
- Use flashcards (Anki recommended)
- Explain concepts without looking

### 2. **Feynman Technique**
1. Study a concept
2. Explain it like teaching a 5-year-old
3. Identify gaps in your explanation
4. Go back and fill gaps
5. Simplify further

### 3. **Interleaving**
Don't practice same topic repeatedly. Mix topics:
```
❌ Bad:  Graph, Graph, Graph, DP, DP, DP
✅ Good: Graph, DP, Tree, Graph, System Design, DP
```

### 4. **Chunking**
Group related concepts into mental models:
```
"Two Pointer" chunk:
  ├── Same direction (fast-slow)
  ├── Opposite direction (start-end)
  ├── Sliding window (fixed/variable)
  └── Multiple arrays
```

---

## 📊 Daily Schedule Template (4-5 hours)

| Time Block | Duration | Activity |
|------------|----------|----------|
| Block 1 | 30 min | **Morning Recall** - Revise yesterday's topics (no notes) |
| Block 2 | 90 min | **New Learning** - Fresh concepts/problems |
| Block 3 | 60 min | **Spaced Revision** - Topics from Day 3, 7, 14 ago |
| Block 4 | 60 min | **Practice** - Solve problems without hints |
| Block 5 | 30 min | **Documentation** - Update revision tracker, create cards |

---

## 🔄 Topic-Specific Revision Strategies

### 📝 1. CODING PATTERNS (DSA)

#### Learning Phase
```
For each pattern:
1. Understand the "when to use" triggers
2. Memorize the template/skeleton code
3. Solve 3-5 problems of increasing difficulty
4. Document edge cases and variations
```

#### Revision Method: **Pattern Cards**
Create a card for each pattern:

```
┌─────────────────────────────────────────┐
│ PATTERN: Sliding Window (Variable)      │
├─────────────────────────────────────────┤
│ TRIGGERS:                               │
│ • "Longest/Shortest subarray with..."   │
│ • "Find subarray satisfying condition"  │
│ • Contiguous elements                   │
├─────────────────────────────────────────┤
│ TEMPLATE:                               │
│ left = 0                                │
│ for right in range(n):                  │
│     # expand window                     │
│     while (invalid):                    │
│         # shrink from left              │
│     # update answer                     │
├─────────────────────────────────────────┤
│ KEY PROBLEMS:                           │
│ 1. Longest Substring Without Repeat     │
│ 2. Minimum Window Substring             │
│ 3. Fruit Into Baskets                   │
└─────────────────────────────────────────┘
```

#### Revision Schedule for Patterns
| Week | Focus | Revision |
|------|-------|----------|
| 1-2 | Arrays, Two Pointers, Sliding Window | Daily recall |
| 3-4 | Binary Search, Sorting | Week 1-2 patterns every 3 days |
| 5-6 | Trees, Graphs (BFS/DFS) | Week 3-4 every 3 days, Week 1-2 weekly |
| 7-8 | Dynamic Programming | Earlier patterns weekly |
| 9-10 | Advanced (Tries, Heaps, Union Find) | All patterns bi-weekly |
| 11-12 | Mock interviews | Rotate all patterns |

#### Quick Revision Drill (15 min)
1. Pick 3 random patterns
2. Write triggers from memory
3. Code template without IDE
4. Name 2 problems for each

---

### 🏗️ 2. SYSTEM DESIGN (HLD)

#### Learning Phase
```
For each system:
1. Understand requirements (functional + non-functional)
2. Learn the building blocks used
3. Understand trade-offs and alternatives
4. Know scaling strategies
```

#### Revision Method: **RESHADED Framework**

For each system, memorize this structure:
```
R - Requirements (Functional + Non-Functional)
E - Estimation (QPS, Storage, Bandwidth)
S - Storage Schema (Database design)
H - High-level Design (Draw from memory!)
A - API Design (Key endpoints)
D - Deep Dives (Bottlenecks, optimizations)
E - Edge cases & Error handling
D - Deployment & Monitoring
```

#### System Design Revision Cards
```
┌──────────────────────────────────────────┐
│ SYSTEM: URL Shortener                    │
├──────────────────────────────────────────┤
│ SCALE: 100M URLs/day, 10:1 read:write    │
├──────────────────────────────────────────┤
│ KEY DECISIONS:                           │
│ • Base62 encoding vs Hash                │
│ • Counter vs Random ID                   │
│ • Cache for hot URLs (80-20 rule)        │
├──────────────────────────────────────────┤
│ COMPONENTS:                              │
│ LB → App Servers → Cache → DB            │
│           ↓                              │
│    ID Generator (ZooKeeper)              │
├──────────────────────────────────────────┤
│ DEEP DIVES:                              │
│ • Analytics pipeline                     │
│ • URL expiration                         │
│ • Custom aliases                         │
└──────────────────────────────────────────┘
```

#### Weekly System Design Revision
| Day | Activity |
|-----|----------|
| Mon | New system - Full study |
| Tue | Recall yesterday's system (whiteboard) |
| Wed | New system - Full study |
| Thu | Recall Wed + partial Mon system |
| Fri | New system - Full study |
| Sat | Recall all 3 systems (10 min each) |
| Sun | Deep dive into weak areas |

#### Building Blocks to Memorize
Revise these independently:
- [ ] Load Balancers (Round Robin, Consistent Hashing)
- [ ] Caching (Write-through, Write-back, Write-around)
- [ ] Database (SQL vs NoSQL, Sharding, Replication)
- [ ] Message Queues (Kafka, RabbitMQ use cases)
- [ ] CDN (Push vs Pull)
- [ ] Consistent Hashing
- [ ] Rate Limiting (Token Bucket, Leaky Bucket)
- [ ] CAP Theorem & PACELC

---

### 🔧 3. LOW-LEVEL DESIGN (LLD)

#### Learning Phase
```
For each problem:
1. Identify entities and relationships
2. Apply SOLID principles
3. Choose appropriate design patterns
4. Handle edge cases and extensibility
```

#### Revision Method: **Pattern-Problem Matrix**

```
┌─────────────────┬─────────────────────────────────┐
│ Design Pattern  │ Classic Problems                │
├─────────────────┼─────────────────────────────────┤
│ Strategy        │ Payment System, Navigation      │
│ Observer        │ Event System, Stock Ticker      │
│ Factory         │ Document Creator, Vehicle       │
│ Singleton       │ Logger, Configuration           │
│ Decorator       │ Pizza Toppings, I/O Streams     │
│ State           │ Vending Machine, ATM            │
│ Command         │ Remote Control, Undo/Redo       │
│ Chain of Resp.  │ Logging Levels, Middleware      │
└─────────────────┴─────────────────────────────────┘
```

#### LLD Revision Card
```
┌──────────────────────────────────────────┐
│ PROBLEM: Parking Lot                     │
├──────────────────────────────────────────┤
│ KEY CLASSES:                             │
│ • ParkingLot (Singleton)                 │
│ • ParkingFloor, ParkingSpot              │
│ • Vehicle (abstract), Car, Bike, Truck   │
│ • Ticket, Payment                        │
├──────────────────────────────────────────┤
│ PATTERNS USED:                           │
│ • Singleton (ParkingLot instance)        │
│ • Strategy (PricingStrategy)             │
│ • Factory (VehicleFactory)               │
├──────────────────────────────────────────┤
│ EXTENSIBILITY POINTS:                    │
│ • New vehicle types                      │
│ • Different pricing strategies           │
│ • Multiple payment methods               │
└──────────────────────────────────────────┘
```

#### LLD Weekly Practice
- **Day 1-2:** Design one system from scratch
- **Day 3:** Revise Day 1-2 design, identify improvements
- **Day 4-5:** New design + partial recall of previous
- **Day 6:** Code key components of one design
- **Day 7:** Review all patterns used during week

---

### 🗣️ 4. BEHAVIORAL (Leadership Principles)

#### The STAR-L Method
```
S - Situation (Brief context)
T - Task (Your responsibility)
A - Action (What YOU did - be specific)
R - Result (Quantifiable impact)
L - Learning (What you'd do differently)
```

#### Revision Method: **Story Bank**

Create 8-10 stories that can flex across multiple questions:

```
┌──────────────────────────────────────────┐
│ STORY: Migrated Monolith to Microservices│
├──────────────────────────────────────────┤
│ CAN ANSWER:                              │
│ ✓ Tell me about a complex project        │
│ ✓ Time you dealt with ambiguity          │
│ ✓ How do you handle disagreements        │
│ ✓ Time you influenced without authority  │
│ ✓ Biggest technical challenge            │
├──────────────────────────────────────────┤
│ KEY METRICS:                             │
│ • 40% latency reduction                  │
│ • 3x deployment frequency                │
│ • Led team of 6 engineers                │
└──────────────────────────────────────────┘
```

#### Behavioral Revision (3x per week)
1. Pick random leadership principle
2. Recall which stories apply
3. Practice one story out loud (2 min max)
4. Record yourself, identify filler words

---

## 📅 90-Day Phase Plan

### Phase 1: Foundation (Days 1-30)
**Goal:** Build strong fundamentals, establish revision habits

| Week | Focus | Daily Split |
|------|-------|-------------|
| 1-2 | Core DSA patterns + 2 System Designs | 3h DSA, 1h SD, 30m revision |
| 3-4 | Intermediate patterns + 3 System Designs | 2.5h DSA, 1.5h SD, 30m revision |

**Revision Rule:** Everything learned gets reviewed on Day 1, 3, 7

### Phase 2: Depth (Days 31-60)
**Goal:** Master complex topics, start LLD

| Week | Focus | Daily Split |
|------|-------|-------------|
| 5-6 | Advanced DSA + 4 System Designs + LLD intro | 2h DSA, 1.5h SD, 1h LLD |
| 7-8 | DP mastery + Complex Systems + LLD patterns | 2h DSA, 1.5h SD, 1h LLD |

**Revision Rule:** Weekly review of all Phase 1 topics + spaced repetition continues

### Phase 3: Integration (Days 61-90)
**Goal:** Mock interviews, fill gaps, peak performance

| Week | Focus | Daily Split |
|------|-------|-------------|
| 9-10 | Mock interviews + Gap filling | 2 mocks/week, focused practice |
| 11-12 | Company-specific prep + Light revision | 3 mocks/week, confidence building |
| 13 | Final revision + Rest | 2h light review, rest before interview |

**Revision Rule:** High-frequency review of weak areas, maintain strong areas

---

## 📋 Revision Tracking System

### Daily Log Template
```markdown
## Date: Feb 10, 2026

### New Topics Learned
- [ ] Topic 1: _______________
- [ ] Topic 2: _______________

### Revisions Done (from schedule)
- [x] Day 1 review: _______________
- [x] Day 3 review: _______________
- [ ] Day 7 review: _______________

### Problems Solved
| Problem | Pattern | Difficulty | Solved Clean? |
|---------|---------|------------|---------------|
|         |         |            |               |

### Confidence Check (1-5)
- DSA Patterns: 
- System Design: 
- LLD: 
- Behavioral: 

### Tomorrow's Revision Queue
- Day 1: Today's topics
- Day 3: Topics from Feb 7
- Day 7: Topics from Feb 3
```

### Weekly Review Template
```markdown
## Week N Review

### What went well?
- 

### What needs more work?
- 

### Patterns I'm weak at:
1. 
2. 

### Revision debt (skipped reviews):
- 

### Adjustment for next week:
- 
```

---

## 🛠️ Tools for Revision

### Recommended Setup
| Purpose | Tool |
|---------|------|
| Flashcards (Spaced Repetition) | **Anki** (with custom decks) |
| System Design Diagrams | **Excalidraw** (redraw from memory) |
| Code Practice | **LeetCode** (spaced repetition feature) |
| Progress Tracking | **Notion** or **Markdown files** |
| Mock Interviews | **Pramp**, **Interviewing.io** |

### Anki Card Templates

**For Coding Patterns:**
```
Front: What pattern for "Find longest subarray with at most K distinct elements"?
Back: Sliding Window (Variable) + HashMap for frequency
```

**For System Design:**
```
Front: How does consistent hashing solve the rehashing problem?
Back: Only K/N keys need remapping when node added/removed (vs all keys in modular hashing)
```

**For Design Patterns:**
```
Front: When to use Strategy pattern?
Back: When you have multiple algorithms for same task, want to switch at runtime, avoid conditionals
```

---

## ⚡ Quick Revision Hacks

### The 2-Minute Rule
If you can't explain a concept in 2 minutes, you don't know it well enough.

### The Whiteboard Test
Every weekend, pick one topic from each area:
1. Draw/code on whiteboard without any reference
2. Compare with your notes
3. Fill gaps immediately

### Sleep on It
Review hardest concepts right before sleep. Memory consolidation happens during sleep.

### Teach Someone
Find a study buddy or use rubber duck debugging. Teaching forces deep understanding.

### The 5-Problem Rule
For each pattern, you should be able to:
1. Recognize pattern from problem description (instant)
2. Code template without thinking (< 2 min)
3. Solve easy problem (< 10 min)
4. Solve medium problem (< 20 min)
5. Identify variations and edge cases

---

## 🎯 Success Metrics

### Weekly Checkpoints
- [ ] All scheduled revisions completed
- [ ] Can recall 80%+ of learned patterns
- [ ] At least 1 mock interview done
- [ ] No revision debt accumulated

### Phase Checkpoints
**End of Phase 1 (Day 30):**
- [ ] 10+ coding patterns memorized
- [ ] 5+ system designs understood deeply
- [ ] Revision habit established

**End of Phase 2 (Day 60):**
- [ ] 20+ coding patterns with variations
- [ ] 10+ system designs
- [ ] 5+ LLD problems
- [ ] All behavioral stories ready

**End of Phase 3 (Day 90):**
- [ ] Can solve most Medium in 20 min
- [ ] Can design any standard system in 35 min
- [ ] Can do LLD in 45 min
- [ ] Confident in all areas

---

## 📌 Golden Rules

1. **Consistency > Intensity** - 4 focused hours daily beats 10 hours on weekends
2. **Revision > New Learning** - Spend 30% time on revision minimum
3. **Active > Passive** - Always test yourself, never just read
4. **Sleep > Extra Hour** - 7-8 hours sleep is non-negotiable for memory
5. **Track Everything** - What gets measured gets improved

---

## 🚀 Start Date: February 9, 2026

**Day 1 Actions:**
1. [ ] Set up Anki with starter decks
2. [ ] Create daily log file
3. [ ] Clear calendar for 4-5 hours daily
4. [ ] Pick first 2 coding patterns to master
5. [ ] Choose first system design to study

---

*"The palest ink is better than the best memory."* - Chinese Proverb

**Remember:** You're not preparing to pass an interview. You're preparing to **demonstrate mastery**. The revision strategy is what separates those who cram from those who truly know.

Good luck! 🍀
