#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/random.h>
#define BUFSIZE  100

MODULE_LICENSE("GPLv3");
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

static ssize_t lobster_write(struct file *file, const char __user *ubuf,size_t count, loff_t *ppos)
{
	return -1;
}

static ssize_t lobster_read(struct file *file, char __user *ubuf,size_t count, loff_t *ppos)
{
	char buf[BUFSIZE];
	int len = 0;
	int random;

	if(*ppos > 0 || count < BUFSIZE)
		return 0;

	get_random_bytes(&random, sizeof(random));
	len += sprintf(buf, "%s\n", lobster_lyrics[random % (sizeof(lobster_lyrics) / sizeof(char*))]);

	if(copy_to_user(ubuf, buf, len))
		return -EFAULT;

	*ppos = len;
	return len;
}

static const struct proc_ops lobster_ops =
{
	.proc_read = lobster_read,
	.proc_write = lobster_write,
};

static int simple_init(void)
{
	ent = proc_create("lobster", 0660, NULL, &lobster_ops);
	return 0;
}

static void simple_cleanup(void)
{
	proc_remove(ent);
}

module_init(simple_init);
module_exit(simple_cleanup);
