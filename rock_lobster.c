#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/random.h>
#include <linux/seq_file.h>
#include <linux/stat.h>

MODULE_LICENSE("Proprietary");
MODULE_AUTHOR("Tobias Maedel");

// Not GPLv3:
// Songwriter: Catherine Elizabeth Pierson / Cynthia Leigh Wilson / Frederick William Schneider / Julian Keith Strickland / Rickey Helton Wilson
// Lyrics by Rock Lobster © Kobalt Music Publishing Ltd.
const char *lobster_lyrics[] = {
	"We were at a party",
	"His earlobe fell in the deep",
	"Someone reached in and grabbed it",
	"It was a rock lobster",
	"Rock lobster",
	"Rock lobster",
	"We were at the beach",
	"Everybody had matching towels",
	"Somebody went under a dock",
	"And there they saw a rock",
	"It wasn't a rock",
	"It was a rock lobster",
	"Rock lobster",
	"Rock lobster",
	"Rock lobster",
	"Rock lobster",
	"Motion in the ocean",
	"His air hose broke",
	"Lots of trouble",
	"Lots of bubble",
	"He was in a jam",
	"S'in a giant clam",
	"Rock rock",
	"Rock lobster",
	"Down, down",
	"Lobster rock",
	"Lobster rock",
	"Let's rock!",
	"Boy's in bikinis",
	"Girls in surfboards",
	"Everybody's rockin'",
	"Everybody's fruggin'",
	"Twistin' 'round the fire",
	"Havin' fun",
	"Bakin' potatoes",
	"Bakin' in the sun",
	"Put on your noseguard",
	"Put on the Lifeguard",
	"Pass the tanning butter",
	"Here comes a stingray",
	"There goes a manta-ray",
	"In walked a jelly fish",
	"There goes a dog-fish",
	"Chased by a cat-fish",
	"In flew a sea robin",
	"Watch out for that piranha",
	"There goes a narwhal",
	"Here comes a bikini whale!",
	"Rock lobster",
	"Rock lobster",
	"Rock lobster",
	"Rock lobster",
};

static struct proc_dir_entry *ent;

static int lobster_show(struct seq_file *seq, void *priv)
{
	unsigned int random;

	get_random_bytes(&random, sizeof(random));
	seq_printf(seq, "%s\n", lobster_lyrics[random % ARRAY_SIZE(lobster_lyrics)]);
	return 0;
}

static int lobster_init(void)
{
	ent = proc_create_single("lobster", S_IRUGO, NULL, lobster_show);
	return 0;
}

static void lobster_cleanup(void)
{
	proc_remove(ent);
}

module_init(lobster_init);
module_exit(lobster_cleanup);
