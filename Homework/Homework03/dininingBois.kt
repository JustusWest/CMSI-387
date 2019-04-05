import java.util.Random
import java.util.concurrent.locks.ReentrantLock

val rand = Random()

class ChopSpork(val name: String) {
    val lock = ReentrantLock()

    fun yoink(philosopher: String) {
        lock.lock()
        println("  $philosopher yoinked $name")
    }

    fun yeet(philosopher: String) {
        lock.unlock()
        println("  $philosopher yeeted $name")
    }
}

class Philosopher(val phil: String, val chopSpork1: ChopSpork, val chopSpork2: ChopSpork) : Thread() {
    override fun run() {
        for (it in 1..20) {
            println("$phil is hungry")
            chopSpork1.yoink(phil)
            chopSpork2.yoink(phil)
            println("$phil is munching $it")
            Thread.sleep(rand.nextInt(300) + 100L)
            chopSpork2.yeet(phil)
            chopSpork1.yeet(phil)
        }
    }
}

fun diningPhilosophers(names: List<String>) {
    val philosophers = mutableListOf<Philosopher>()
    val length = names.size
    val chopSporks = List(length) { ChopSpork("ChopSpork ${it + 1}") }
    names.forEachIndexed(fun(i: Int, j: String) {
        var index1: Int = i
        var index2: Int = (i + 1) % length
        if (index2 < index1) {
            index1 = index2
            index2 = i
        }
        val p: Philosopher = Philosopher(j, chopSporks[index1], chopSporks[index2])
        p.start()
        philosophers += p
    })
    for (it in philosophers) it.join()
}

fun main(args: Array<String>) {
    val bois: List<String> = listOf("Roniger", "Roniger Jr I", "Roniger Jr II", "Roniger Jr III", "Roniger Jr IV")
    diningPhilosophers(bois)
}