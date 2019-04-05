import java.util.Random
import java.util.concurrent.locks.ReentrantLock

val rand = Random()

class ChopSpork(val name: String) {
    val lock = ReentrantLock()

    fun pickUp(philosopher: String) {
        lock.lock()
        println("  $philosopher yoinked up $name")
    }

    fun putDown(philosopher: String) {
        lock.unlock()
        println("  $philosopher yeeted $name")
    }
}

class Philosopher(val pname: String, val f1: ChopSpork, val f2: ChopSpork) : Thread() {
    override fun run() {
        (1..20).forEach {
            println("$pname is hungo")
            f1.pickUp(pname)
            f2.pickUp(pname)
            println("$pname is munching $it")
            Thread.sleep(rand.nextInt(300) + 100L)
            f2.putDown(pname)
            f1.putDown(pname)
        }
    }
}

fun diningPhilosophers(names: List<String>) {
    val size = names.size
    val ChopSporks = List(size) { ChopSpork("ChopSpork ${it + 1}") }
    val philosophers = mutableListOf<Philosopher>()
    names.forEachIndexed { i, n ->
        var i1 = i
        var i2 = (i + 1) % size
        if (i2 < i1) {
            i1 = i2
            i2 = i
        }
        val p = Philosopher(n, ChopSporks[i1], ChopSporks[i2])
        p.start()
        philosophers.add(p)
    }
    philosophers.forEach { it.join() }
}

fun main(args: Array<String>) {
    val names = listOf("Roniger1", "Roniger2", "Roniger3", "Mike", "Toal")
    diningPhilosophers(names)
}